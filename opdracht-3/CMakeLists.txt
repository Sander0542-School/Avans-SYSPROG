cmake_minimum_required(VERSION 3.20)
project(opdracht_3)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(plugins)
add_subdirectory(tester)

add_executable(${PROJECT_NAME} main.cpp)
