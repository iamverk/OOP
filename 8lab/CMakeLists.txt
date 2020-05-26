cmake_minimum_required(VERSION 3.15)
project(80)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)


add_executable(80
        point.h
        point.cpp
        factory.cpp
        factory.h
        figure.h
        hexagon.h
        main.cpp
        pentagon.h
        hexagon.cpp
        pentagon.cpp
        rhombus.cpp
        processor.cpp
        processor.h
        rhombus.h
        subscriber.cpp
        subscriber.h)
