#声明要求的cmake最低版本
cmake_minimum_required(VERSION 2.8)

#设置为调试模式
set(CMAKE_BUILD_TYPE "debug")
#声明一个cmake公程
project(HelloSLAM)

#生成共享库
add_library(hello_shared SHARED libHelloSLAM.cpp)

#添加一个可执行程序
#语法:add_executable(程序名 源文件名)
add_executable(HelloSLAM helloSLAM.cpp)
add_executable(useHello useHello.cpp)

#链接共享库
target_link_libraries(useHello hello_shared)
