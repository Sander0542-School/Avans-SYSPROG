cmake_minimum_required(VERSION 3.21)
project(opdracht_5-server)

set(CMAKE_CXX_STANDARD 20)

include_directories(../common)

file(GLOB_RECURSE SOURCE_COMMON ../common/*.cpp)

add_custom_target(copy_assets COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/resources ${CMAKE_CURRENT_BINARY_DIR}/resources)

add_executable(${PROJECT_NAME} ${SOURCE_COMMON} main.cpp RandomUtil.cpp)
add_dependencies(${PROJECT_NAME} copy_assets)
