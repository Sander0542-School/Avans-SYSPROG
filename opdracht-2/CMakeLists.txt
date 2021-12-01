cmake_minimum_required(VERSION 3.20)
project(opdracht_2)

set(CMAKE_CXX_STANDARD 20)

include_directories(common)

add_custom_target(copy_assets COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/resources ${CMAKE_CURRENT_BINARY_DIR}/resources)

add_subdirectory(plugins)

add_executable(${PROJECT_NAME} main.cpp PluginWrapper.cpp)
add_dependencies(${PROJECT_NAME} copy_assets)
