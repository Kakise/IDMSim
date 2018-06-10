cmake_minimum_required(VERSION 3.10)
project(IDMSim)

set(CMAKE_CXX_STANDARD 11)

add_executable(IDMSim main.cpp Lib/IDM.cpp Lib/IDM.h)