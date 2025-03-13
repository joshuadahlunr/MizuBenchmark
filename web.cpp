#define ANKERL_NANOBENCH_IMPLEMENT
#include "nanobench.h"

// #define MIZU_ENABLE_TRACING
#define MIZU_IMPLEMENTATION
#include "fib_program.h"
#include "bubble_program.h"

int main() {
	ankerl::nanobench::Bench().run("Mizu(WEB) fib(40)", []{
		registers_and_stack env = {};
		setup_enviornment(env);

		MIZU_START_FROM_ENVIORNMENT(fib_program, env);
		// ankerl::nanobench::doNotOptimizeAway(env);

		assert(*(env.memory + registers::a(0)) == 102334155);
	});

	std::cout << std::string(20, '-') << std::endl;

	ankerl::nanobench::Bench().minEpochIterations(109).run("Mizu(WEB) bubble(1100)", []{
		registers_and_stack env = {};
		setup_enviornment(env);

		MIZU_START_FROM_ENVIORNMENT(bubble_program, env);

		auto start = env.memory.end() - numbers.size();
		for(size_t i = 0; i < sorted.size(); ++i)
			assert(start[i] == sorted[i]);
	});
}