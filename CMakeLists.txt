cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-static -Wall")

project(MAIN)
include_directories(include)
file(GLOB SOURCES "main/*.cpp")

add_executable(MAIN main/main.cpp)
