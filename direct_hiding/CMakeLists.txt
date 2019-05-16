cmake_minimum_required(VERSION 3.13)
project(Enc)

set(CMAKE_CXX_STANDARD 14)


set(SOURCE_FILES main.cpp img_convert.h enc_file.h math_rela.h)

find_package(OpenCV REQUIRED)
include_directories(/usr/local/include)


add_executable(direct_hiding ${SOURCE_FILES})

target_link_libraries(direct_hiding ${OpenCV_LIBS})
