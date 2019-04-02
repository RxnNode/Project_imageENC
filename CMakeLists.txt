cmake_minimum_required(VERSION 3.13)
project(project_imageENC C)

set(CMAKE_C_STANDARD 99)

find_package(libjpeg)
set(JPEGLIB_INCLUDE_DIR /usr/local/Cellar/jpeg-turbo/2.0.2/include/)
set(JPEGLIB_LIBRARY_DIR /usr/local/Cellar/jpeg-turbo/2.0.2/lib)

include_directories(${JPEGLIB_INCLUDE_DIR})
include_directories(${JPEGLIB_LIBRARY_DIR})

add_executable(project_imageENC main.c)