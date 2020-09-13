cmake_minimum_required(VERSION 3.0.0)
project(useGeometry VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(useGeometry useGeometry.cpp)

# include_directories("/usr/include/eigen3")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
