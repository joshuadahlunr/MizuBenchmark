function fib(n)
	if n <= 2 then
		return 1
	else
		return fib(n - 1) + fib(n - 2)
	end
end

assert(fib(40) == 102334155, "Fib failed!")
