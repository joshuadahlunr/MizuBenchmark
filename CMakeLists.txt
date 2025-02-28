cmake_minimum_required(VERSION 3.21)
project(MizuBenchmarks C CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(MizuVM)
add_subdirectory(nanobench)

set(BENCHMARK_MODES desktop web wasi)
set(BENCHMARK_MODE desktop CACHE STRING "The mode [desktop, web, or wasi] to build the benchmark in.")
set_property(CACHE BENCHMARK_MODE PROPERTY STRINGS ${BENCHMARK_MODES})

if(BENCHMARK_MODE STREQUAL "desktop")
	add_executable(program_dump program_dump.cpp)
	target_link_libraries(program_dump mizu::vm)

	add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/fib.mizu.bin COMMAND program_dump)

	add_executable(desktop desktop.cpp ${CMAKE_CURRENT_BINARY_DIR}/fib.mizu.bin)
	target_link_libraries(desktop mizu::vm nanobench)
elseif(BENCHMARK_MODE STREQUAL "web")
	set(CMAKE_EXECUTABLE_SUFFIX ".html")
	add_executable(web web.cpp)
	target_link_libraries(web mizu::vm nanobench)
elseif(BENCHMARK_MODE STREQUAL "wasi")
	add_executable(wasi web.cpp)
	target_link_libraries(wasi mizu::vm nanobench)
else()
	message(FATAL_ERROR "Invalid Benchmark Mode")
endif()