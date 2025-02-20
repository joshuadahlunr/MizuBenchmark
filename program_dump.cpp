#define MIZU_IMPLEMENTATION
#include "fib_program.h"
#include <fstream>

int main() {
	std::ofstream fib("fib.mizu.bin", std::ios::binary);
	fp::raii::dynarray program = mizu::to_binary(fp::view<const mizu::opcode>{fib_program, sizeof(fib_program)/sizeof(fib_program[0])});
	fib.write((char*)program.data(), program.size());
}