# chassis control
This repository contains a Gazebo simulation model of shooting range world and a differential drive robot. It is meant to be a very flexible simulation platform that supports single and multiple chassis simulations in the shooting range.

## dependences and enviroment
ubuntu 18.04 with ros melodic
Before you launch the simulation, you should download some basic gazebo models in [here](https://github.com/osrf/gazebo_models).
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
mkdir chassis_gazebo_ws && cd chassis_gazebo_ws
git clone https://github.com/molguitianzn/chassis-control.git
catkin_make
```
launch the simulation
```bash
cd ~/yourworkingdir/chassis_gazebo_ws
source devel/setup.bash
roslaunch robot_and_world robots_world.launch
```
