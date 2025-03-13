cmake_minimum_required(VERSION 3.21)

set(MIZU_ENABLE_FFI OFF CACHE BOOL "Weather or not to enable the Foreign Function Interface")
set(MIZU_NO_EXCEPTIONS ON CACHE BOOL "When enabled Mizu is built without exceptions")
add_subdirectory(../MizuVM mizu)
add_subdirectory(../nanobench nanobench)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(MizuEspressif)