#include "nanobench.h"

#define MIZU_IMPLEMENTATION
#include "fib_program.h"
#include "bubble_program.h"
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

	ankerl::nanobench::Bench().run("Mizu(file + loading) fib(40)", []{
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

		registers_and_stack env = {};
		setup_enviornment(env);

		MIZU_START_FROM_ENVIORNMENT(fib_file_program, env);

		assert(*(env.memory + registers::a(0)) == 102334155);
	});

	ankerl::nanobench::Bench().run("APE(native) fib(40)", []{
		assert_with_side_effects(system("../fib.ape.com") == 0);
	});

	ankerl::nanobench::Bench().run("Node fib(40)", []{
		assert_with_side_effects(system("node ../fib.js") == 0);
	});

	ankerl::nanobench::Bench().run("LuaJIT fib(40)", []{
		assert_with_side_effects(system("luajit ../fib.lua") == 0);
	});

	ankerl::nanobench::Bench().run("Lua fib(40)", []{
		assert_with_side_effects(system("lua ../fib.lua") == 0);
	});

	ankerl::nanobench::Bench().run("Python fib(40)", []{
		assert_with_side_effects(system("python ../fib.py") == 0);
	});

	ankerl::nanobench::Bench().run("WASM3(c) fib(40)", []{
		assert_with_side_effects(system("wasm3 ../fib.wasm") == 0);
	});


	std::cout << std::string(20, '-') << std::endl;


	ankerl::nanobench::Bench().run("Mizu bubble(100)", []{
		registers_and_stack env = {};
		setup_enviornment(env);

		MIZU_START_FROM_ENVIORNMENT(bubble_program, env);

		assert(*(env.memory.end() - 1) == 1975);
	});

	ankerl::nanobench::Bench().run("APE(native) bubble(100)", []{
		assert_with_side_effects(system("../bubble.ape.com") == 0);
	});

	ankerl::nanobench::Bench().run("Node bubble(100)", []{
		assert_with_side_effects(system("node ../bubble.js") == 0);
	});

	ankerl::nanobench::Bench().run("LuaJIT bubble(100)", []{
		assert_with_side_effects(system("luajit ../bubble.lua") == 0);
	});

	ankerl::nanobench::Bench().run("Lua bubble(100)", []{
		assert_with_side_effects(system("lua ../bubble.lua") == 0);
	});

	ankerl::nanobench::Bench().run("Python bubble(100)", []{
		assert_with_side_effects(system("python ../bubble.py") == 0);
	});

	ankerl::nanobench::Bench().run("WASM3(c) bubble(100)", []{
		assert_with_side_effects(system("wasm3 ../bubble.wasm") == 0);
	});
}