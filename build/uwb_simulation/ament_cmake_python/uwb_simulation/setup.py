from setuptools import find_packages
from setuptools import setup

setup(
    name='uwb_simulation',
    version='0.0.1',
    packages=find_packages(
        include=('uwb_simulation', 'uwb_simulation.*')),
)
