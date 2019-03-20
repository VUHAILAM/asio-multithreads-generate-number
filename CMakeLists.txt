cmake_minimum_required(VERSION 3.0)

project(bt)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

find_package(Boost 1.68.0 REQUIRED COMPONENTS thread system filesystem)

add_executable(
    bt
    Generator.cpp
    main.cpp
)

include_directories(${Boost_INCLUDE_DIR})

target_include_directories(bt PUBLIC ./include)

target_link_libraries(bt ${Boost_LIBRARIES})
target_link_libraries(bt ws2_32 wsock32)
