cmake_minimum_required(VERSION 3.20)
project(lib)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE LIB_SOURCES *.cpp)

add_library(${PROJECT_NAME}-static STATIC ${LIB_SOURCES})

add_library(${PROJECT_NAME}-shared SHARED ${LIB_SOURCES})
