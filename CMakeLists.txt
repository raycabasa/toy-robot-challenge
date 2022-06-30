cmake_minimum_required(VERSION 3.23)

# Set the project name
project(ToyRobot)

add_executable(ToyRobot ToyRobotApp.cpp)

# Use C++17 version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

