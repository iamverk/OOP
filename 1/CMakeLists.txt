cmake_minimum_required(VERSION 3.2)

project(Long)

add_executable(Long
    Source.cpp
        Long.cpp)

set_property(TARGET Long PROPERTY CXX_STANDART 11)
