cmake_minimum_required(VERSION 3.0)

project(useEigen)

set(CMAKE_BUILD_TYPE "Debug")

set(CMAKE_CXX_FLAGS "-O3")

include_directories("usr/include")

add_executable(eigenMatrix eigenMatrix.cpp)




 
