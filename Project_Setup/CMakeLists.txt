cmake_minimum_required(VERSION 3.20.4)

project(glfw_example)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/libraries)

add_executable(glfw_example ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libraries/include)

target_link_libraries(glfw_example glfw GL GLEW)
#target_link_libraries(glfw_example glfw3dll GL GLEW)

target_sources(
    glfw_example PUBLIC
    src/main.cpp
)