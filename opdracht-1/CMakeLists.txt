cmake_minimum_required(VERSION 3.20)
project(opdracht_1)

set(CMAKE_CXX_STANDARD 20)

if (WIN32 OR WIN64)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif ()

include_directories(lib)

add_subdirectory(lib)

add_custom_target(copy_assets COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/resources ${CMAKE_CURRENT_BINARY_DIR}/resources)
add_custom_target(copy_dlls COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/lib/lib-shared.dll ${CMAKE_CURRENT_BINARY_DIR})

add_executable(${PROJECT_NAME}-static main.cpp)
add_dependencies(${PROJECT_NAME}-static copy_assets)
target_link_libraries(${PROJECT_NAME}-static PRIVATE lib-static)

add_executable(${PROJECT_NAME}-shared main.cpp)
add_dependencies(${PROJECT_NAME}-shared copy_assets)
target_link_libraries(${PROJECT_NAME}-shared PRIVATE lib-shared)
add_dependencies(${PROJECT_NAME}-shared copy_dlls)
