cmake_minimum_required(VERSION 3.6)
project(project1_grade)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

add_executable(q1_01 cpp/ch01_arrays_and_strings/q1_01_is_unique/q1_01_is_unique.cpp)