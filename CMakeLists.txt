cmake_minimum_required(VERSION 3.21)
project(MizuBenchmarks C CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(MizuVM)
add_subdirectory(nanobench)

add_executable(program_dump program_dump.cpp)
target_link_libraries(program_dump mizu::vm)

add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/fib.mizu.bin COMMAND program_dump)

add_executable(desktop desktop.cpp ${CMAKE_CURRENT_BINARY_DIR}/fib.mizu.bin)
target_link_libraries(desktop mizu::vm nanobench)