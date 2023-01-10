# chassis control
This repository contains a Gazebo simulation model of shooting range world and a differential drive robot. It is meant to be a very flexible simulation platform that supports single and multiple chassis simulations in the shooting range.

## dependences and enviroment
Ubuntu 18.04 with ROS melodic.
Before you launch the simulation, you should download some basic gazebo models [here](https://github.com/osrf/gazebo_models).
```bash
cd ~/.gazebo/ # if you do not have the dir, create it firstly
mkdir -p models
cd models
git clone https://github.com/osrf/gazebo_models.git
```

## usage
create your working directory and download the code
```bash
cd ~/yourworkingdir/
git clone https://github.com/molguitianzn/chassis-control.git
cd chassis-control
catkin_make
```
launch the simulation platform.
```bash
cd ~/yourworkingdir/chassis-control
source devel/setup.bash
roslaunch robot_and_world robots_world.launch
```
Then you can launch gmapping node.
```bash
roslaunch robot_localization launch_gmapping.launch
```
Move the robot to finish the mapping task.
```bash
rosrun teleop_twist_keyboard teleop_twist_keyboard.py /cmd_vel:=/robot1/cmd_vel
```
Robot1 is used to create the map as default. However, you can modify the "robot_frame_prefix" argument field in [launch_gmapping.launch](robot_localization/launch/launch_gmapping.launch) with any robot you want.
To save the map, run the following line of code.
```bash
roslaunch robot_localization save_map.launch
```
I have created a map in [robot_localization/map/shooting_range_map1.yaml](robot_localization/map/shooting_range_map1.yaml)