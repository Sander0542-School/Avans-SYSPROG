cmake_minimum_required(VERSION 3.21)
project(opdracht_5-client)

set(CMAKE_CXX_STANDARD 20)

include_directories(../common)

file(GLOB_RECURSE SOURCE_COMMON ../common/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_COMMON} main.cpp)
