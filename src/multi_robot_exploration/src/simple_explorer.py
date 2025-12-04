#!/usr/bin/env python3
"""
Improved Autonomous Explorer with better obstacle avoidance
更好的避障逻辑，遇到障碍物时智能绕行
"""

import math
import random
import numpy as np
from typing import Dict, List, Optional, Tuple
from collections import defaultdict
import threading

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy, HistoryPolicy

from nav_msgs.msg import OccupancyGrid, Odometry
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan
from std_msgs.msg import String


class SimpleExplorer(Node):
    def __init__(self):
        super().__init__('simple_explorer')
        
        self.declare_parameter('robot_names', ['robot1', 'robot2'])
        self.declare_parameter('linear_speed', 0.22)
        self.declare_parameter('angular_speed', 0.8)
        self.declare_parameter('goal_tolerance', 1.0)
        self.declare_parameter('obstacle_distance', 0.5)
        self.declare_parameter('min_frontier_size', 5)
        self.declare_parameter('goal_timeout', 25.0)
        
        self.robot_names = self.get_parameter('robot_names').value
        self.linear_speed = self.get_parameter('linear_speed').value
        self.angular_speed = self.get_parameter('angular_speed').value
        self.goal_tolerance = self.get_parameter('goal_tolerance').value
        self.obstacle_distance = self.get_parameter('obstacle_distance').value
        self.min_frontier_size = self.get_parameter('min_frontier_size').value
        self.goal_timeout = self.get_parameter('goal_timeout').value
        
        # 机器人状态
        self.robot_poses: Dict[str, Tuple[float, float, float]] = {}
        self.robot_goals: Dict[str, Optional[Tuple[float, float]]] = {name: None for name in self.robot_names}
        self.robot_scans: Dict[str, Optional[LaserScan]] = {name: None for name in self.robot_names}
        self.maps: Dict[str, Optional[OccupancyGrid]] = {name: None for name in self.robot_names}
        
        # 目标跟踪
        self.goal_start_time: Dict[str, float] = {name: 0.0 for name in self.robot_names}
        self.avoidance_direction: Dict[str, int] = {name: (1 if i % 2 == 0 else -1) for i, name in enumerate(self.robot_names)}
        self.stuck_counter: Dict[str, int] = {name: 0 for name in self.robot_names}
        self.last_positions: Dict[str, Tuple[float, float]] = {}
        
        # 避障状态
        self.avoiding: Dict[str, bool] = {name: False for name in self.robot_names}
        self.avoid_start_time: Dict[str, float] = {name: 0.0 for name in self.robot_names}
        self.avoid_duration = 2.0  # 避障持续时间
        
        # 全局黑名单
        self.global_blacklist: List[Tuple[float, float, float]] = []
        self.blacklist_radius = 2.5
        self.blacklist_duration = 200.0
        
        # 已访问位置
        self.visited_positions: List[Tuple[float, float]] = []
        self.visit_radius = 1.5
        
        # 恢复模式
        self.recovery_mode: Dict[str, bool] = {name: False for name in self.robot_names}
        self.recovery_start: Dict[str, float] = {name: 0.0 for name in self.robot_names}
        
        # 分区
        self.robot_regions: Dict[str, Tuple[float, float]] = {
            'robot1': (-20.0, 0.0),
            'robot2': (0.0, 20.0),
        }
        
        self.lock = threading.Lock()
        
        map_qos = QoSProfile(
            durability=DurabilityPolicy.TRANSIENT_LOCAL,
            reliability=ReliabilityPolicy.RELIABLE,
            history=HistoryPolicy.KEEP_LAST, depth=1)
        
        odom_qos = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE, depth=10)
        
        scan_qos = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE, depth=5)
        
        self.cmd_pubs: Dict[str, any] = {}
        
        for robot_name in self.robot_names:
            self.cmd_pubs[robot_name] = self.create_publisher(
                Twist, f'/{robot_name}/cmd_vel', 10)
            
            self.create_subscription(
                Odometry, f'/{robot_name}/odom',
                lambda msg, name=robot_name: self.odom_callback(msg, name), odom_qos)
            
            self.create_subscription(
                LaserScan, f'/{robot_name}/scan',
                lambda msg, name=robot_name: self.scan_callback(msg, name), scan_qos)
            
            self.create_subscription(
                OccupancyGrid, f'/{robot_name}/map',
                lambda msg, name=robot_name: self.map_callback(msg, name), map_qos)
        
        self.status_pub = self.create_publisher(String, '/exploration/status', 10)
        
        self.control_timer = self.create_timer(0.1, self.control_loop)
        self.frontier_timer = self.create_timer(1.0, self.find_and_assign_frontiers)
        self.stuck_timer = self.create_timer(1.0, self.check_stuck)
        self.visit_timer = self.create_timer(2.0, self.record_visited)
        
        self.get_logger().info(f'SimpleExplorer initialized for {self.robot_names}')

    def odom_callback(self, msg: Odometry, robot_name: str):
        pos = msg.pose.pose.position
        q = msg.pose.pose.orientation
        yaw = math.atan2(2*(q.w*q.z + q.x*q.y), 1 - 2*(q.y*q.y + q.z*q.z))
        with self.lock:
            self.robot_poses[robot_name] = (pos.x, pos.y, yaw)

    def scan_callback(self, msg: LaserScan, robot_name: str):
        with self.lock:
            self.robot_scans[robot_name] = msg

    def map_callback(self, msg: OccupancyGrid, robot_name: str):
        with self.lock:
            self.maps[robot_name] = msg

    def record_visited(self):
        with self.lock:
            for robot_name in self.robot_names:
                if robot_name in self.robot_poses:
                    rx, ry, _ = self.robot_poses[robot_name]
                    is_new = True
                    for vx, vy in self.visited_positions:
                        if math.sqrt((rx - vx)**2 + (ry - vy)**2) < self.visit_radius:
                            is_new = False
                            break
                    if is_new:
                        self.visited_positions.append((rx, ry))

    def is_visited(self, x: float, y: float) -> bool:
        for vx, vy in self.visited_positions:
            if math.sqrt((x - vx)**2 + (y - vy)**2) < self.visit_radius:
                return True
        return False

    def is_blacklisted(self, x: float, y: float) -> bool:
        current_time = self.get_clock().now().nanoseconds / 1e9
        self.global_blacklist = [
            (bx, by, bt) for bx, by, bt in self.global_blacklist
            if current_time - bt < self.blacklist_duration
        ]
        for bx, by, _ in self.global_blacklist:
            if math.sqrt((x - bx)**2 + (y - by)**2) < self.blacklist_radius:
                return True
        return False

    def blacklist_goal(self, x: float, y: float, robot_name: str):
        current_time = self.get_clock().now().nanoseconds / 1e9
        self.global_blacklist.append((x, y, current_time))
        self.get_logger().info(f'{robot_name} blacklisted ({x:.2f}, {y:.2f})')

    def check_stuck(self):
        with self.lock:
            current_time = self.get_clock().now().nanoseconds / 1e9
            
            for robot_name in self.robot_names:
                if robot_name not in self.robot_poses:
                    continue
                
                rx, ry, _ = self.robot_poses[robot_name]
                
                # 恢复模式检查
                if self.recovery_mode[robot_name]:
                    if current_time - self.recovery_start[robot_name] > 3.0:
                        self.recovery_mode[robot_name] = False
                        self.get_logger().info(f'{robot_name} recovery done')
                    continue
                
                # 移动检测
                if robot_name in self.last_positions:
                    lx, ly = self.last_positions[robot_name]
                    dist_moved = math.sqrt((rx - lx)**2 + (ry - ly)**2)
                    
                    if dist_moved < 0.02:
                        self.stuck_counter[robot_name] += 1
                    else:
                        self.stuck_counter[robot_name] = 0
                
                self.last_positions[robot_name] = (rx, ry)
                
                # 卡住处理
                if self.stuck_counter[robot_name] > 5:
                    goal = self.robot_goals[robot_name]
                    if goal is not None:
                        self.blacklist_goal(goal[0], goal[1], robot_name)
                        self.robot_goals[robot_name] = None
                    
                    self.stuck_counter[robot_name] = 0
                    self.avoidance_direction[robot_name] *= -1
                    self.recovery_mode[robot_name] = True
                    self.recovery_start[robot_name] = current_time
                    self.get_logger().warn(f'{robot_name} stuck!')
                
                # 超时处理
                if self.robot_goals[robot_name] is not None:
                    elapsed = current_time - self.goal_start_time[robot_name]
                    if elapsed > self.goal_timeout:
                        goal = self.robot_goals[robot_name]
                        self.blacklist_goal(goal[0], goal[1], robot_name)
                        self.robot_goals[robot_name] = None
                        self.get_logger().warn(f'{robot_name} timeout')

    def find_and_assign_frontiers(self):
        with self.lock:
            map_to_use = None
            for robot_name in self.robot_names:
                if self.maps.get(robot_name) is not None:
                    map_to_use = self.maps[robot_name]
                    break
            
            if map_to_use is None:
                return
            
            all_frontiers = self._detect_frontiers(map_to_use)
            
            if not all_frontiers:
                self.get_logger().info('Exploration complete!')
                return
            
            for robot_name in self.robot_names:
                if self.robot_goals[robot_name] is not None:
                    continue
                if self.recovery_mode[robot_name]:
                    continue
                if robot_name not in self.robot_poses:
                    continue
                
                rx, ry, ryaw = self.robot_poses[robot_name]
                region_x_min, region_x_max = self.robot_regions.get(robot_name, (-20.0, 20.0))
                
                scored_frontiers = []
                for fx, fy, size in all_frontiers:
                    dist = math.sqrt((fx - rx)**2 + (fy - ry)**2)
                    
                    if dist < 1.2 or dist > 12.0:
                        continue
                    if self.is_blacklisted(fx, fy):
                        continue
                    
                    # 检查其他机器人
                    too_close = False
                    for other_name in self.robot_names:
                        if other_name == robot_name:
                            continue
                        other_goal = self.robot_goals.get(other_name)
                        if other_goal and math.sqrt((fx - other_goal[0])**2 + (fy - other_goal[1])**2) < 3.0:
                            too_close = True
                            break
                        if other_name in self.robot_poses:
                            ox, oy, _ = self.robot_poses[other_name]
                            if math.sqrt((fx - ox)**2 + (fy - oy)**2) < 2.0:
                                too_close = True
                                break
                    
                    if too_close:
                        continue
                    
                    # 评分
                    in_region = region_x_min <= fx <= region_x_max
                    region_bonus = 4.0 if in_region else -2.0
                    visited_penalty = -6.0 if self.is_visited(fx, fy) else 0.0
                    
                    angle_to_frontier = math.atan2(fy - ry, fx - rx)
                    angle_diff = abs(self._normalize_angle(angle_to_frontier - ryaw))
                    angle_bonus = (1.0 - angle_diff / math.pi) * 2.0
                    
                    dist_penalty = -dist * 0.15
                    size_bonus = min(size * 0.15, 4.0)
                    
                    score = region_bonus + visited_penalty + angle_bonus + dist_penalty + size_bonus + random.uniform(0, 1.5)
                    scored_frontiers.append((fx, fy, score, size))
                
                if scored_frontiers:
                    scored_frontiers.sort(key=lambda x: x[2], reverse=True)
                    best = scored_frontiers[0]
                    self.robot_goals[robot_name] = (best[0], best[1])
                    self.goal_start_time[robot_name] = self.get_clock().now().nanoseconds / 1e9
                    self.get_logger().info(f'{robot_name} -> ({best[0]:.2f}, {best[1]:.2f})')

    def _detect_frontiers(self, map_msg: OccupancyGrid) -> List[Tuple[float, float, int]]:
        info = map_msg.info
        h, w = info.height, info.width
        grid = np.array(map_msg.data, dtype=np.int8).reshape((h, w))
        
        FREE_THRESH = 50
        free_mask = (grid >= 0) & (grid < FREE_THRESH)
        unknown_mask = grid == -1
        
        adj_unknown = (
            np.roll(unknown_mask, 1, axis=0) |
            np.roll(unknown_mask, -1, axis=0) |
            np.roll(unknown_mask, 1, axis=1) |
            np.roll(unknown_mask, -1, axis=1))
        
        frontier_mask = free_mask & adj_unknown
        fy, fx = np.where(frontier_mask)
        
        if len(fx) == 0:
            return []
        
        clusters = defaultdict(list)
        grid_size = 10
        for x, y in zip(fx, fy):
            key = (x // grid_size, y // grid_size)
            clusters[key].append((x, y))
        
        frontiers = []
        for points in clusters.values():
            if len(points) < self.min_frontier_size:
                continue
            cx = sum(p[0] for p in points) / len(points)
            cy = sum(p[1] for p in points) / len(points)
            world_x = info.origin.position.x + (cx + 0.5) * info.resolution
            world_y = info.origin.position.y + (cy + 0.5) * info.resolution
            frontiers.append((world_x, world_y, len(points)))
        
        return frontiers

    def control_loop(self):
        status_parts = []
        current_time = self.get_clock().now().nanoseconds / 1e9
        
        with self.lock:
            for robot_name in self.robot_names:
                if robot_name not in self.robot_poses:
                    continue
                
                rx, ry, ryaw = self.robot_poses[robot_name]
                goal = self.robot_goals[robot_name]
                scan = self.robot_scans.get(robot_name)
                
                cmd = Twist()
                
                # 获取障碍物信息
                obs_front, obs_left, obs_right, best_direction = self._check_obstacles_detailed(scan)
                
                # 恢复模式
                if self.recovery_mode[robot_name]:
                    cmd.linear.x = -0.15
                    cmd.angular.z = self.angular_speed * self.avoidance_direction[robot_name]
                    status_parts.append(f"{robot_name}:REC")
                    self.cmd_pubs[robot_name].publish(cmd)
                    continue
                
                # 检查避障状态
                if self.avoiding[robot_name]:
                    if current_time - self.avoid_start_time[robot_name] > self.avoid_duration:
                        self.avoiding[robot_name] = False
                    else:
                        # 继续避障动作
                        cmd.linear.x = 0.1
                        cmd.angular.z = self.angular_speed * self.avoidance_direction[robot_name] * 0.8
                        status_parts.append(f"{robot_name}:AVOIDING")
                        self.cmd_pubs[robot_name].publish(cmd)
                        continue
                
                if goal is None:
                    # 无目标时搜索
                    if obs_front:
                        cmd.linear.x = -0.05
                        cmd.angular.z = self.angular_speed * self.avoidance_direction[robot_name]
                    else:
                        cmd.linear.x = 0.1
                        cmd.angular.z = 0.25 * self.avoidance_direction[robot_name]
                    status_parts.append(f"{robot_name}:SEARCH")
                else:
                    gx, gy = goal
                    dist = math.sqrt((gx - rx)**2 + (gy - ry)**2)
                    
                    if dist < self.goal_tolerance:
                        self.robot_goals[robot_name] = None
                        self.get_logger().info(f'{robot_name} reached!')
                        status_parts.append(f"{robot_name}:DONE")
                        self.cmd_pubs[robot_name].publish(Twist())
                        continue
                    
                    angle_to_goal = math.atan2(gy - ry, gx - rx)
                    angle_diff = self._normalize_angle(angle_to_goal - ryaw)
                    
                    if obs_front:
                        # 前方障碍：开始避障
                        self.avoiding[robot_name] = True
                        self.avoid_start_time[robot_name] = current_time
                        
                        # 选择避障方向：优先选择更空旷的一侧
                        if best_direction != 0:
                            self.avoidance_direction[robot_name] = best_direction
                        elif not obs_left:
                            self.avoidance_direction[robot_name] = 1
                        elif not obs_right:
                            self.avoidance_direction[robot_name] = -1
                        
                        cmd.linear.x = -0.08
                        cmd.angular.z = self.angular_speed * self.avoidance_direction[robot_name]
                        status_parts.append(f"{robot_name}:AVOID")
                    elif abs(angle_diff) > 0.35:
                        # 转向目标
                        cmd.linear.x = 0.05
                        cmd.angular.z = self.angular_speed * np.sign(angle_diff) * min(1.0, abs(angle_diff) * 1.5)
                        status_parts.append(f"{robot_name}:TURN")
                    else:
                        # 前进
                        speed = self.linear_speed
                        if obs_left or obs_right:
                            speed *= 0.7
                            # 轻微转向远离障碍物
                            if obs_left and not obs_right:
                                cmd.angular.z = -0.2
                            elif obs_right and not obs_left:
                                cmd.angular.z = 0.2
                        cmd.linear.x = speed
                        cmd.angular.z += 0.8 * angle_diff
                        status_parts.append(f"{robot_name}:GO({dist:.1f})")
                
                self.cmd_pubs[robot_name].publish(cmd)
        
        if status_parts:
            msg = String()
            msg.data = " | ".join(status_parts)
            self.status_pub.publish(msg)

    def _check_obstacles_detailed(self, scan: Optional[LaserScan]) -> Tuple[bool, bool, bool, int]:
        """返回: (前方障碍, 左侧障碍, 右侧障碍, 最佳转向方向)"""
        if scan is None:
            return False, False, False, 0
        
        num = len(scan.ranges)
        ranges = np.array(scan.ranges)
        ranges = np.where(np.isfinite(ranges), ranges, scan.range_max)
        
        sector = num // 12  # 30度
        
        # 前方 (-30到+30度)
        front_idx = list(range(num - sector, num)) + list(range(0, sector))
        front_ranges = ranges[front_idx]
        
        # 左前方 (+30到+60度)
        left_front_ranges = ranges[sector:sector*2]
        
        # 右前方 (-60到-30度)
        right_front_ranges = ranges[num-sector*2:num-sector]
        
        # 左侧 (+30到+90度)
        left_ranges = ranges[sector:sector*3]
        
        # 右侧 (-90到-30度)
        right_ranges = ranges[num-sector*3:num-sector]
        
        obs_front = np.any(front_ranges < self.obstacle_distance)
        obs_left = np.any(left_ranges < self.obstacle_distance * 0.7)
        obs_right = np.any(right_ranges < self.obstacle_distance * 0.7)
        
        # 计算最佳转向方向（哪边更空旷）
        left_avg = np.mean(left_front_ranges)
        right_avg = np.mean(right_front_ranges)
        
        best_direction = 0
        if left_avg > right_avg + 0.3:
            best_direction = 1  # 左转
        elif right_avg > left_avg + 0.3:
            best_direction = -1  # 右转
        
        return obs_front, obs_left, obs_right, best_direction

    def _normalize_angle(self, angle: float) -> float:
        while angle > math.pi:
            angle -= 2 * math.pi
        while angle < -math.pi:
            angle += 2 * math.pi
        return angle


def main(args=None):
    rclpy.init(args=args)
    node = SimpleExplorer()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        for name in node.robot_names:
            node.cmd_pubs[name].publish(Twist())
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()