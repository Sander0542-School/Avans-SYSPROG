cmake_minimum_required(VERSION 3.20)
project(plugins)

set(CMAKE_CXX_STANDARD 20)

include_directories(../common)

add_library(${PROJECT_NAME}-uppercase SHARED UppercasePlugin.cpp)
set_target_properties(${PROJECT_NAME}-uppercase PROPERTIES SUFFIX ".plug")

add_library(${PROJECT_NAME}-lowercase SHARED LowercasePlugin.cpp)
set_target_properties(${PROJECT_NAME}-lowercase PROPERTIES SUFFIX ".plug")

add_library(${PROJECT_NAME}-remove-consonants SHARED RemoveConsonantsPlugin.cpp)
set_target_properties(${PROJECT_NAME}-remove-consonants PROPERTIES SUFFIX ".plug")
