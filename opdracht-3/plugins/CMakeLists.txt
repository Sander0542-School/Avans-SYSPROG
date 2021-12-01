cmake_minimum_required(VERSION 3.20)
project(plugins)

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME}-crash SHARED CrashPlugin.cpp)
set_target_properties(${PROJECT_NAME}-crash PROPERTIES SUFFIX ".plug")
