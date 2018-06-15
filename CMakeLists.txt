cmake_minimum_required(VERSION 3.10)
project(IDMSim)

set(CMAKE_CXX_STANDARD 11)

find_package(SDL2 REQUIRED)

add_executable(IDMSim
        Lib/IDM.cpp
        Lib/IDM.h
        Lib/Vehicle.cpp
        Lib/Vehicle.h
        main.cpp
        Lib/lib.h)

target_link_libraries(IDMSim ${SDL2_LIBRARIES})