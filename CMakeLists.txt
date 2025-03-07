cmake_minimum_required(VERSION 3.14...3.29)
project(
        bg_framework
        VERSION 0.1
        DESCRIPTION "Open-source C++ framework for text-based games"
        LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

file(GLOB_RECURSE PROJECT_SRC "lib/*.cpp")
add_library(${PROJECT_NAME} STATIC ${PROJECT_SRC})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/bg_framework)
