cmake_minimum_required(VERSION 3.21)
project(MizuBenchmarks C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

add_subdirectory(MizuVM)
add_subdirectory(nanobench)

set(BENCHMARK_MODES desktop web wasi arduino)
set(BENCHMARK_MODE desktop CACHE STRING "The mode [desktop, web, wasi, or arduino] to build the benchmark in.")
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
elseif(BENCHMARK_MODE STREQUAL "arduino")
	add_library(arduino INTERFACE)
	target_link_libraries(arduino INTERFACE mizu::vm)
	target_compile_options(arduino INTERFACE -mmcu=atmega2560 -dead-strip -foptimize-sibling-calls -O3)
	target_link_options(arduino INTERFACE -mmcu=atmega2560)

	add_executable(arduino.fib arduino.cpp)
	target_link_libraries(arduino.fib PUBLIC arduino)

	add_executable(arduino.bubble arduino.cpp)
	target_link_libraries(arduino.bubble PUBLIC arduino)
	target_compile_definitions(arduino.bubble PUBLIC BENCHMARK_BUBBLE)
else()
	message(FATAL_ERROR "Invalid Benchmark Mode")
endif()