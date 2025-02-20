using System.Diagnostics;

long fib(int n) {
	if (n <= 2) return 1; 
	return fib(n - 1) + fib(n - 2);
}

long res = fib(40);
Trace.Assert(res == 102334155);
