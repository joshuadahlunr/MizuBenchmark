#include "nanobench.h"

#define MIZU_IMPLEMENTATION
#include "fib_program.h"
#include <cstring>
#include <fstream>
#include <iostream>

int main() {
	fp::raii::dynarray<opcode> fib_data; {
		std::ifstream f("fib.mizu.bin", std::ios::binary);
		f.seekg(0, std::ios::end);
		size_t size = f.tellg();
		fp::raii::dynarray data = fp::dynarray<std::byte>{}.resize(size);
		f.seekg(0, std::ios::beg);
		f.read((char*)data.data(), size);
		fib_data = from_binary(data.view_full());
	}
	opcode* fib_file_program = (opcode*)fib_data.data();
	assert(std::memcmp(fib_file_program, fib_program, sizeof(fib_program)) == 0);


	ankerl::nanobench::Bench().run("Mizu(file) fib(40)", [fib_file_program]{
		registers_and_stack env = {};
		setup_enviornment(env);

		MIZU_START_FROM_ENVIORNMENT(fib_file_program, env);

		assert(*(env.memory + registers::a(0)) == 102334155);
	});

	ankerl::nanobench::Bench().run("Mizu fib(40)", []{
		registers_and_stack env = {};
		setup_enviornment(env);

		MIZU_START_FROM_ENVIORNMENT(fib_program, env);

		assert(*(env.memory + registers::a(0)) == 102334155);
	});
}