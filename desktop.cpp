#include "nanobench.h"

#define MIZU_IMPLEMENTATION
#include "fib_program.h"
#include "bubble_program.h"
#include <cstring>
#include <fstream>
#include <iostream>

#ifdef _WIN32
	#define PATH_PREFIX ".\\PATH\\"
#else
	#define PATH_PREFIX
#endif

int main() {
	fp::raii::dynarray<opcode> fib_data; {
		std::ifstream f("fib.mizu.bin", std::ios::binary);
		assert(f.good());
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
			assert(f.good());
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

#ifdef _WIN32
	ankerl::nanobench::Bench().run("EXE(native) fib(40)", []{
		assert_with_side_effects(system("..\\fib.exe") == 0);
	});
#elif defined(__arm64__)
	ankerl::nanobench::Bench().run("EXE(native) fib(40)", []{
		assert_with_side_effects(system("../fib.arm64.osx") == 0);
	});
#else
	ankerl::nanobench::Bench().run("APE(native) fib(40)", []{
		assert_with_side_effects(system("../fib.ape.com") == 0);
	});
#endif

	ankerl::nanobench::Bench().run("Node fib(40)", []{
		assert_with_side_effects(system("node ../fib.js") == 0);
	});

	ankerl::nanobench::Bench().minEpochIterations(100).run("C# fib(40)", []{
		assert_with_side_effects(system("../dotnet/fib") == 0);
	});

	ankerl::nanobench::Bench().run("LuaJIT fib(40)", []{
		assert_with_side_effects(system(PATH_PREFIX "luajit ../fib.lua") == 0);
	});

	ankerl::nanobench::Bench().run("Lua fib(40)", []{
		assert_with_side_effects(system(PATH_PREFIX "lua ../fib.lua") == 0);
	});

	ankerl::nanobench::Bench().run("Python fib(40)", []{
		assert_with_side_effects(system("python ../fib.py") == 0);
	});

	ankerl::nanobench::Bench().run("Numba fib(40)", []{
		assert_with_side_effects(system("numba ../fib.py") == 0);
	});

	ankerl::nanobench::Bench().run("WASM3(c) fib(40)", []{
		assert_with_side_effects(system(PATH_PREFIX "wasm3 ../fib.wasm") == 0);
	});


	std::cout << std::string(20, '-') << std::endl;


	ankerl::nanobench::Bench().run("Mizu(file + loading) bubble(100)", []{
		fp::raii::dynarray<opcode> bubble_program_data; {
			std::ifstream f("bubble.mizu.bin", std::ios::binary);
			assert(f.good());
			f.seekg(0, std::ios::end);
			size_t size = f.tellg();
			fp::raii::dynarray data = fp::dynarray<std::byte>{}.resize(size);
			f.seekg(0, std::ios::beg);
			f.read((char*)data.data(), size);
			bubble_program_data = from_binary(data.view_full());
		}
		opcode* bubble_file_program = (opcode*)bubble_program_data.data();
		update_bubble_pointers(bubble_file_program, numbers.data(), sorted.data());
		assert(std::memcmp(bubble_file_program, bubble_program, sizeof(bubble_program)) == 0);

		registers_and_stack env = {};
		setup_enviornment(env);

		MIZU_START_FROM_ENVIORNMENT(bubble_file_program, env);
		ankerl::nanobench::doNotOptimizeAway(env);

		auto start = env.memory.end() - numbers.size();
		for(size_t i = 0; i < 100; ++i)
			assert(start[i] == sorted[i]);
	});
	ankerl::nanobench::Bench().run("Mizu(file + loading + data loading) bubble(100)", []{
		fp::raii::dynarray<opcode> bubble_program_data; {
			std::ifstream f("bubble.mizu.bin", std::ios::binary);
			assert(f.good());
			f.seekg(0, std::ios::end);
			size_t size = f.tellg();
			fp::raii::dynarray data = fp::dynarray<std::byte>{}.resize(size);
			f.seekg(0, std::ios::beg);
			f.read((char*)data.data(), size);
			bubble_program_data = from_binary(data.view_full());
		}
		fp::raii::dynarray<std::byte> bubble_data; {
			std::ifstream f("bubble.data.bin", std::ios::binary);
			assert(f.good());
			f.seekg(0, std::ios::end);
			size_t size = f.tellg();
			bubble_data = fp::dynarray<std::byte>{}.resize(size);
			f.seekg(0, std::ios::beg);
			f.read((char*)bubble_data.data(), size);
		}
		opcode* bubble_file_program = (opcode*)bubble_program_data.data();
		assert(
			(update_bubble_pointers(bubble_file_program, numbers.data(), sorted.data()),
			std::memcmp(bubble_file_program, bubble_program, sizeof(bubble_program)) == 0)
		);
		assert(std::memcmp(bubble_data, numbers.data(), sizeof(uint64_t) * numbers.size()));
		assert(std::memcmp(bubble_data + sizeof(uint64_t) * sorted.size(), sorted.data(), sizeof(uint64_t) * sorted.size()));
		update_bubble_pointers(bubble_file_program, bubble_data + sizeof(uint64_t) * numbers.size(), bubble_data);

		registers_and_stack env = {};
		setup_enviornment(env);

		MIZU_START_FROM_ENVIORNMENT(bubble_file_program, env);
		ankerl::nanobench::doNotOptimizeAway(env);

		auto start = env.memory.end() - numbers.size();
		for(size_t i = 0; i < 100; ++i)
			assert(start[i] == sorted[i]);
	});

#ifdef _WIN32
	ankerl::nanobench::Bench().run("EXE(native) bubble(100)", []{
		assert_with_side_effects(system("..\\bubble.exe") == 0);
	});
#elif defined(__arm64__)
	ankerl::nanobench::Bench().run("EXE(native) bubble(100)", []{
		assert_with_side_effects(system("../bubble.arm64.osx") == 0);
	});
#else
	ankerl::nanobench::Bench().run("APE(native) bubble(100)", []{
		assert_with_side_effects(system("../bubble.ape.com") == 0);
	});
#endif

	ankerl::nanobench::Bench().run("Node bubble(100)", []{
		assert_with_side_effects(system("node ../bubble.js") == 0);
	});

	ankerl::nanobench::Bench().minEpochIterations(100).run("C# bubble(1100)", []{
		assert_with_side_effects(system("../dotnet/bubble") == 0);
	});

	ankerl::nanobench::Bench().run("LuaJIT bubble(100)", []{
		assert_with_side_effects(system(PATH_PREFIX "luajit ../bubble.lua") == 0);
	});

	ankerl::nanobench::Bench().run("Lua bubble(100)", []{
		assert_with_side_effects(system(PATH_PREFIX "lua ../bubble.lua") == 0);
	});

	ankerl::nanobench::Bench().run("Python bubble(100)", []{
		assert_with_side_effects(system("python ../bubble.py") == 0);
	});

	ankerl::nanobench::Bench().minEpochIterations(100).run("Numba bubble(1100)", []{
		assert_with_side_effects(system("numba ../bubble.py") == 0);
	});

	ankerl::nanobench::Bench().run("WASM3(c) bubble(100)", []{
		assert_with_side_effects(system(PATH_PREFIX "wasm3 ../bubble.wasm") == 0);
	});
}