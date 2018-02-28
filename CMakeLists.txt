cmake_minimum_required(VERSION 3.5)
project(Leetcode CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-sign-compare")

add_subdirectory(test)
add_subdirectory(code)
add_subdirectory(interview)
add_subdirectory(offer)
add_subdirectory(algorithm)
