idf_component_register(SRCS "main.cpp" INCLUDE_DIRS ".")

target_link_libraries(${COMPONENT_LIB} PUBLIC mizu::vm nanobench)
target_compile_options(${COMPONENT_LIB} PUBLIC -foptimize-sibling-calls -O3 -Wno-error=array-bounds)
