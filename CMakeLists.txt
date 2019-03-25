cmake_minimum_required(VERSION 3.0)

project(gen_number_with_5_threads)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(
    gen_number_with_5_threads
    Generator.cpp
    main.cpp
)

target_include_directories(gen_number_with_5_threads PUBLIC ./include)
target_link_libraries(gen_number_with_5_threads ws2_32 wsock32)
