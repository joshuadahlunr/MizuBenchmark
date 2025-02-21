#include <assert.h>

long long fib(int n) {
	if (n <= 2) return 1; 
	return fib(n - 1) + fib(n - 2);
}

int main() {
	assert(fib(40) == 102334155);
	return 0;
}
