#!/usr/bin/env python3
"""
Pose Graph Optimizer with UWB Range Edges
Based on: "Inter-Robot Range Measurements in Pose Graph Optimization"
"""

import math
import numpy as np
from typing import Dict, List, Optional, Tuple
from dataclasses import dataclass, field
from collections import defaultdict
import threading

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy

from nav_msgs.msg import Odometry, OccupancyGrid
from geometry_msgs.msg import Pose, PoseStamped, TransformStamped
from std_msgs.msg import Header
from tf2_ros import TransformBroadcaster, StaticTransformBroadcaster

try:
    from uwb_simulation.msg import UwbRange, UwbRangeArray
    UWB_AVAILABLE = True
except ImportError:
    UWB_AVAILABLE = False


@dataclass
class PoseNode:
    node_id: int
    robot_id: str
    x: float
    y: float
    z: float
    yaw: float
    timestamp: float
    covariance: np.ndarray = field(default_factory=lambda: np.eye(3) * 0.01)


@dataclass 
class OdometryEdge:
    source_id: int
    target_id: int
    robot_id: str
    dx: float
    dy: float
    dyaw: float
    information: np.ndarray = field(default_factory=lambda: np.eye(3) * 100)


@dataclass
class RangeEdge:
    source_id: int
    target_id: int
    source_robot: str
    target_robot: str
    measured_range: float
    range_std: float
    switch_variable: float = 1.0


class PoseGraphOptimizer(Node):
    def __init__(self):
        super().__init__('pose_graph_optimizer')
        
        self.declare_parameter('robot_names', ['robot1', 'robot2'])
        self.declare_parameter('optimization_rate', 1.0)
        self.declare_parameter('range_edge_weight', 50.0)
        self.declare_parameter('switch_prior_weight', 1.0)
        self.declare_parameter('max_iterations', 20)
        self.declare_parameter('convergence_threshold', 1e-6)
        self.declare_parameter('use_sim_time', True)
        self.declare_parameter('node_distance_threshold', 0.2)
        
        self.robot_names = self.get_parameter('robot_names').value
        self.optimization_rate = self.get_parameter('optimization_rate').value
        self.range_edge_weight = self.get_parameter('range_edge_weight').value
        self.switch_prior_weight = self.get_parameter('switch_prior_weight').value
        self.max_iterations = self.get_parameter('max_iterations').value
        self.convergence_threshold = self.get_parameter('convergence_threshold').value
        self.node_distance_threshold = self.get_parameter('node_distance_threshold').value
        
        self.nodes: Dict[int, PoseNode] = {}
        self.odometry_edges: List[OdometryEdge] = []
        self.range_edges: List[RangeEdge] = []
        self.last_node_id: Dict[str, int] = {}
        self.robot_transforms: Dict[str, np.ndarray] = {name: np.eye(4) for name in self.robot_names}
        self.lock = threading.Lock()
        
        odom_qos = QoSProfile(reliability=ReliabilityPolicy.BEST_EFFORT,
                              durability=DurabilityPolicy.VOLATILE, depth=10)
        
        self.odom_subs = {}
        for robot_name in self.robot_names:
            self.odom_subs[robot_name] = self.create_subscription(
                Odometry, f'/{robot_name}/odom',
                lambda msg, name=robot_name: self.odom_callback(msg, name), odom_qos)
        
        if UWB_AVAILABLE:
            self.range_sub = self.create_subscription(
                UwbRangeArray, '/uwb/ranges', self.range_callback, 10)
        
        self.tf_broadcaster = TransformBroadcaster(self)
        self.opt_timer = self.create_timer(1.0 / self.optimization_rate, self.optimize_callback)
        self.tf_timer = self.create_timer(0.1, self.publish_transforms)
        
        self.get_logger().info(f'PoseGraphOptimizer initialized for {self.robot_names}')

    def _normalize_angle(self, angle: float) -> float:
        while angle > math.pi: angle -= 2 * math.pi
        while angle < -math.pi: angle += 2 * math.pi
        return angle

    def odom_callback(self, msg: Odometry, robot_name: str):
        with self.lock:
            pos = msg.pose.pose.position
            q = msg.pose.pose.orientation
            yaw = math.atan2(2*(q.w*q.z + q.x*q.y), 1 - 2*(q.y*q.y + q.z*q.z))
            timestamp = msg.header.stamp.sec + msg.header.stamp.nanosec * 1e-9
            
            should_add = True
            if robot_name in self.last_node_id:
                last = self.nodes[self.last_node_id[robot_name]]
                dist = math.sqrt((pos.x - last.x)**2 + (pos.y - last.y)**2)
                if dist < self.node_distance_threshold and abs(self._normalize_angle(yaw - last.yaw)) < 0.15:
                    should_add = False
            
            if should_add:
                node_id = len(self.nodes)
                self.nodes[node_id] = PoseNode(node_id, robot_name, pos.x, pos.y, pos.z, yaw, timestamp)
                
                if robot_name in self.last_node_id:
                    last_id = self.last_node_id[robot_name]
                    last = self.nodes[last_id]
                    dx, dy = pos.x - last.x, pos.y - last.y
                    dyaw = self._normalize_angle(yaw - last.yaw)
                    cos_y, sin_y = math.cos(last.yaw), math.sin(last.yaw)
                    self.odometry_edges.append(OdometryEdge(
                        last_id, node_id, robot_name,
                        cos_y*dx + sin_y*dy, -sin_y*dx + cos_y*dy, dyaw))
                
                self.last_node_id[robot_name] = node_id

    def _find_closest_node(self, robot_id: str, time_msg) -> Optional[PoseNode]:
        timestamp = time_msg.sec + time_msg.nanosec * 1e-9
        closest, min_diff = None, float('inf')
        for node in self.nodes.values():
            if node.robot_id == robot_id:
                diff = abs(node.timestamp - timestamp)
                if diff < min_diff:
                    min_diff, closest = diff, node
        return closest if min_diff < 0.5 else None

    def range_callback(self, msg: UwbRangeArray):
        with self.lock:
            for r in msg.ranges:
                if not r.is_valid: continue
                src = self._find_closest_node(r.source_robot_id, r.measurement_time)
                tgt = self._find_closest_node(r.target_robot_id, r.measurement_time)
                if src and tgt and src.node_id != tgt.node_id:
                    exists = any(e.source_id == src.node_id and e.target_id == tgt.node_id 
                                for e in self.range_edges[-20:])
                    if not exists:
                        self.range_edges.append(RangeEdge(
                            src.node_id, tgt.node_id, r.source_robot_id, 
                            r.target_robot_id, r.range, r.range_std))

    def _sigmoid(self, x: float) -> float:
        return 1.0 / (1.0 + math.exp(-max(-50, min(50, x))))

    def optimize_callback(self):
        with self.lock:
            if len(self.nodes) < 2: return
            self._optimize_graph()

    def _optimize_graph(self):
        node_list = sorted(self.nodes.values(), key=lambda n: n.node_id)
        n = len(node_list)
        if n < 2: return
        
        x = np.zeros(3 * n)
        for i, node in enumerate(node_list):
            x[3*i:3*i+3] = [node.x, node.y, node.yaw]
        
        for iteration in range(self.max_iterations):
            H = np.zeros((3*n, 3*n))
            b = np.zeros(3*n)
            total_cost = 0.0
            
            # Odometry edges
            for edge in self.odometry_edges:
                i = next((idx for idx, nd in enumerate(node_list) if nd.node_id == edge.source_id), None)
                j = next((idx for idx, nd in enumerate(node_list) if nd.node_id == edge.target_id), None)
                if i is None or j is None: continue
                
                xi, yi, ti = x[3*i], x[3*i+1], x[3*i+2]
                xj, yj, tj = x[3*j], x[3*j+1], x[3*j+2]
                
                c, s = math.cos(ti), math.sin(ti)
                dx, dy = xj - xi, yj - yi
                pred_dx = c*dx + s*dy
                pred_dy = -s*dx + c*dy
                pred_dyaw = self._normalize_angle(tj - ti)
                
                error = np.array([pred_dx - edge.dx, pred_dy - edge.dy, 
                                 self._normalize_angle(pred_dyaw - edge.dyaw)])
                
                Ji = np.array([[-c, -s, -s*dx + c*dy], [s, -c, -c*dx - s*dy], [0, 0, -1]])
                Jj = np.array([[c, s, 0], [-s, c, 0], [0, 0, 1]])
                
                omega = edge.information
                H[3*i:3*i+3, 3*i:3*i+3] += Ji.T @ omega @ Ji
                H[3*i:3*i+3, 3*j:3*j+3] += Ji.T @ omega @ Jj
                H[3*j:3*j+3, 3*i:3*i+3] += Jj.T @ omega @ Ji
                H[3*j:3*j+3, 3*j:3*j+3] += Jj.T @ omega @ Jj
                b[3*i:3*i+3] += Ji.T @ omega @ error
                b[3*j:3*j+3] += Jj.T @ omega @ error
                total_cost += error.T @ omega @ error
            
            # Range edges with switchable constraints
            for edge in self.range_edges:
                i = next((idx for idx, nd in enumerate(node_list) if nd.node_id == edge.source_id), None)
                j = next((idx for idx, nd in enumerate(node_list) if nd.node_id == edge.target_id), None)
                if i is None or j is None: continue
                
                xi, yi = x[3*i], x[3*i+1]
                xj, yj = x[3*j], x[3*j+1]
                
                dx, dy = xj - xi, yj - yi
                pred_range = math.sqrt(dx*dx + dy*dy + 1e-6)
                error = pred_range - edge.measured_range
                
                psi = self._sigmoid(edge.switch_variable)
                weight = self.range_edge_weight / (edge.range_std ** 2)
                
                Jr_i = np.array([-dx/pred_range, -dy/pred_range, 0])
                Jr_j = np.array([dx/pred_range, dy/pred_range, 0])
                
                w = psi * weight
                H[3*i:3*i+3, 3*i:3*i+3] += w * np.outer(Jr_i, Jr_i)
                H[3*i:3*i+3, 3*j:3*j+3] += w * np.outer(Jr_i, Jr_j)
                H[3*j:3*j+3, 3*i:3*i+3] += w * np.outer(Jr_j, Jr_i)
                H[3*j:3*j+3, 3*j:3*j+3] += w * np.outer(Jr_j, Jr_j)
                b[3*i:3*i+3] += w * Jr_i * error
                b[3*j:3*j+3] += w * Jr_j * error
                
                total_cost += psi * weight * error * error
                
                # Update switch variable
                if abs(error) > 3 * edge.range_std:
                    edge.switch_variable = max(-10, edge.switch_variable - 0.5)
                else:
                    edge.switch_variable = min(10, edge.switch_variable + 0.1)
            
            # Fix first node
            H[0:3, 0:3] += np.eye(3) * 1e6
            
            try:
                H += np.eye(3*n) * 1e-6
                dx = np.linalg.solve(H, -b)
                x += dx
                
                for i in range(n):
                    x[3*i+2] = self._normalize_angle(x[3*i+2])
                
                if np.linalg.norm(dx) < self.convergence_threshold:
                    break
            except np.linalg.LinAlgError:
                self.get_logger().warn('Optimization failed')
                break
        
        # Update nodes
        for i, node in enumerate(node_list):
            node.x, node.y, node.yaw = x[3*i], x[3*i+1], x[3*i+2]

    def publish_transforms(self):
        with self.lock:
            now = self.get_clock().now()
            
            for robot_name in self.robot_names:
                if robot_name not in self.last_node_id: continue
                node = self.nodes[self.last_node_id[robot_name]]
                
                t = TransformStamped()
                t.header.stamp = now.to_msg()
                t.header.frame_id = 'world'
                t.child_frame_id = f'{robot_name}/odom'
                t.transform.translation.x = 0.0
                t.transform.translation.y = 0.0
                t.transform.translation.z = 0.0
                t.transform.rotation.w = 1.0
                self.tf_broadcaster.sendTransform(t)

    def get_optimized_poses(self) -> Dict[str, List[Tuple[float, float, float]]]:
        with self.lock:
            result = defaultdict(list)
            for node in sorted(self.nodes.values(), key=lambda n: n.timestamp):
                result[node.robot_id].append((node.x, node.y, node.yaw))
            return dict(result)


def main(args=None):
    rclpy.init(args=args)
    node = PoseGraphOptimizer()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
