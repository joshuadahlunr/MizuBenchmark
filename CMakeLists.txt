cmake_minimum_required(VERSION 3.21)
project(MizuBenchmarks C CXX)

add_subdirectory(MizuVM)
add_subdirectory(nanobench)

add_executable(desktop_web hello.cpp)
target_link_libraries(desktop_web mizu::vm nanobench)