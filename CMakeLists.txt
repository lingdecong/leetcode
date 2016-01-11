cmake_minimum_required(VERSION 3.3)
project(leetcode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp PalindromeNumber.hpp)
add_executable(leetcode ${SOURCE_FILES})