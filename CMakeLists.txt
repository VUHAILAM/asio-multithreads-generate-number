cmake_minimum_required(VERSION 3.0)

project(bt)

find_package(Boost 1.68.0 REQUIRED COMPONENTS thread system filesystem)

add_executable(
    bt
    Generator.cpp
    main.cpp
)

include_directories(${Boost_INCLUDE_DIR})

target_link_libraries(bt ${Boost_LIBRARIES})
target_link_libraries(bt ws2_32 wsock32)
