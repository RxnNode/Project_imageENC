cmake_minimum_required(VERSION 3.13)
project(Enc)

set(CMAKE_CXX_STANDARD 14)


set(SOURCE_FILES main.cpp)

find_package(OpenCV REQUIRED)
include_directories(/usr/local/include)


add_executable(Enc ${SOURCE_FILES})

target_link_libraries(Enc ${OpenCV_LIBS})
