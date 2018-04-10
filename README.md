Getting Started
===============

Create a workspace for building ROS packages, using catkin and wstool:

    mkdir ~/example_ws && cd ~/example_ws
    wstool init src
    catkin_init_workspace src
    catkin_make

Now, whenever you want to use your workspace, just source its setup file, like so:

    source ~/example_ws/devel/setup.bash

Best practice is to create a new workspace for each project you're working on. For
more information, please see the ROS Tutorials:

http://wiki.ros.org/ROS/Tutorials
# IMU
