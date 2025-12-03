from setuptools import find_packages
from setuptools import setup

setup(
    name='multi_robot_slam',
    version='0.0.1',
    packages=find_packages(
        include=('multi_robot_slam', 'multi_robot_slam.*')),
)
