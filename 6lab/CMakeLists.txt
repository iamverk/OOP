cmake_minimum_required(VERSION 3.15)
project(60)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(60
        allocator.h
        list.h
        main.cpp
        point.h
        rhombus.h)
