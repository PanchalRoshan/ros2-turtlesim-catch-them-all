# 🐢 ROS 2 Turtlesim Catch Them All

A ROS 2 Jazzy project that demonstrates publishers, subscribers, custom messages, custom services, launch files, timers, and multi-node communication by creating a game where turtles are spawned and automatically caught.

---

## 🚀 Project Overview

This project was developed while learning ROS 2 Jazzy.

The application automatically spawns turtles at random positions in the turtlesim simulator. A controller node continuously tracks the spawned turtles and commands the main turtle to catch them one by one.

The project demonstrates practical ROS 2 communication using custom interfaces and multiple packages.

---

## 📦 Workspace Structure

```
ros2_ws
│
├── src
│   ├── my_cpp_pkg
│   ├── my_robot_interfaces
│   ├── my_robot_bringup
│   └── turtlesim_catch_them_all
│
├── build
├── install
└── log
```

---

## 📂 Packages

### my_cpp_pkg

Contains practice ROS 2 C++ programs including:

- Publishers
- Subscribers
- Services
- Clients
- Timers
- Parameters

---

### my_robot_interfaces

Contains custom ROS 2 interfaces.

### Custom Messages

- HardwareStatus.msg
- LedPanelState.msg
- Turtle.msg
- TurtleArray.msg

### Custom Services

- CatchTurtle.srv
- ComputeRectangleArea.srv
- SetLed.srv

---

### my_robot_bringup

Contains launch files and configuration.

Launch files

- turtle.launch.xml
- number_app.launch.xml
- turtlesim_catch_them_all.launch.xml

Configuration

- turtle.yaml
- catch_them_all_config.yaml
- number_app.yaml

---

### turtlesim_catch_them_all

Main project package.

Contains

- Turtle Spawner Node
- Turtle Controller Node

Features

- Random turtle spawning
- Automatic turtle tracking
- Automatic turtle catching
- Uses custom messages
- Uses custom services
- ROS 2 timers
- Publishers & Subscribers

---

## 🛠 Technologies Used

- ROS 2 Jazzy
- C++
- rclcpp
- turtlesim
- CMake
- Ubuntu Linux

---

## ▶️ Build

```bash
cd ~/ros2_ws

colcon build

source install/setup.bash
```

---

## ▶️ Run

```bash
ros2 launch my_robot_bringup turtlesim_catch_them_all.launch.xml
```

---

## 🎯 Concepts Demonstrated

- ROS 2 Nodes
- Publishers
- Subscribers
- Services
- Clients
- Custom Messages
- Custom Services
- Parameters
- Launch Files
- Timers
- Object-Oriented Programming in ROS 2
- Multi-package Workspace

---

## 📸 Demo

Add screenshots or GIFs here.

Example:

```
images/demo.gif
```

---

## 📈 Future Improvements

- RViz visualization
- Navigation integration
- Action Server implementation
- Lifecycle Nodes
- Multi-robot support
- Gazebo simulation

---

## 👨‍💻 Author

**Parangi Panchal**

GitHub:
https://github.com/PanchalRoshan

---

## ⭐ If you found this project useful

Please consider giving the repository a ⭐ on GitHub.
