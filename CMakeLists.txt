cmake_minimum_required(VERSION 3.17)
project(CPS_ELEVATOR_PROJECT)

set(CMAKE_CXX_STANDARD 14)

add_executable(CPS_ELEVATOR_PROJECT main.cpp classes/elevator.cpp classes/elevator.h classes/node.cpp classes/node.h standalone_headers/location.h)