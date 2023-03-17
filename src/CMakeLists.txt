cmake_minimum_required(VERSION 3.23.2)
project(src)

include_directories("lib/SDL/include")

set(CMAKE_CXX_STANDARD 17)

add_executable(src main.cpp Project.h Input.h Object.h GameProcess.h Map.h Util.h Util.cpp Input.cpp Map.cpp Object.cpp GameProcess.cpp)
