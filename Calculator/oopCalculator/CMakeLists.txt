cmake_minimum_required(VERSION 3.14)

project(oopCalculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(oopCalculator
  src/main.cpp
  src/mathOperations.cpp

  include/mathOperations.h
)
