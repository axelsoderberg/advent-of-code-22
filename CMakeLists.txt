cmake_minimum_required(VERSION 3.10)

# set the project name
project(AdventofCode2022)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(day1 "src/day1.cpp")
add_executable(day2 "src/day2.cpp")
add_executable(day3 "src/day3.cpp")
add_executable(day4 "src/day4.cpp")
add_executable(day5 "src/day5.cpp")
