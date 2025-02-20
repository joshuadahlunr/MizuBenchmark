#define MIZU_IMPLEMENTATION
#include "fib_program.h"
#include "bubble_program.h"
#include <fstream>

int main() {
	{
		std::ofstream fib("fib.mizu.bin", std::ios::binary);
		fp::raii::dynarray program = mizu::to_binary(fp::view<const mizu::opcode>{fib_program, sizeof(fib_program)/sizeof(fib_program[0])});
		fib.write((char*)program.data(), program.size());
	}{
		std::ofstream bubble("bubble.mizu.bin", std::ios::binary);
		fp::raii::dynarray program = mizu::to_binary(fp::view<const mizu::opcode>{bubble_program, sizeof(bubble_program)/sizeof(bubble_program[0])});
		bubble.write((char*)program.data(), program.size());
	}{
		std::ofstream bubble_data("bubble.data.bin", std::ios::binary);
		bubble_data.write((char*)sorted.data(), sorted.size() * sizeof(sorted[0]));
		bubble_data.write((char*)numbers.data(), numbers.size() * sizeof(numbers[0]));
	}
	return 0;
}