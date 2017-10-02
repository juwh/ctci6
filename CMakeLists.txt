cmake_minimum_required(VERSION 3.6)
project(ctci6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

add_executable(q1_01 cpp/ch01_arrays_and_strings/q1_01_is_unique/q1_01_is_unique.cpp)
add_executable(q1_02 cpp/ch01_arrays_and_strings/q1_02_check_permutation/q1_02_check_permutation.cpp)
add_executable(q1_03 cpp/ch01_arrays_and_strings/q1_03_urlify/q1_03_urlify.cpp)