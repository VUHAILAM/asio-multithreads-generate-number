cmake_minimum_required(VERSION 3.0)

project(bt)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(
    bt
    Generator.cpp
    main.cpp
)

target_include_directories(bt PUBLIC ./include)
target_link_libraries(bt ws2_32 wsock32)
