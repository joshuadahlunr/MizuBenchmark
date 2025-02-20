function fib(n) {
	if (n <= 2) return 1;
	return fib(n - 1) + fib(n - 2);
}

console.assert(fib(40) == 102334155, "Fib failed!")