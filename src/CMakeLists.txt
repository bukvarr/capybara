cmake_minimum_required(VERSION 3.24)
project(src)

set(CMAKE_CXX_STANDARD 17)

add_executable(src main.cpp Project.h Input.h Object.h Object.cpp GameProcess.h Map.h Map.cpp Util.cpp)
