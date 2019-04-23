cmake_minimum_required(VERSION 3.13)
project(project_imageENC C)

set(CMAKE_C_STANDARD 99)

find_package(OpenCV)


add_executable(project_imageENC main.c main.cpp)