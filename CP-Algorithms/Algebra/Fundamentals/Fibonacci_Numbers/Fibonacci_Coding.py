N = 30

fib = [0 for i in range(N)]

def largestFiboLessOrEqual(n):
	fib[0] = 1
	fib[1] = 2

	i = 2
	while(fib[i - 1] <= n):
		fib[i] = fib[i - 1] + fib[i - 2]
		i += 1
	
	return (i - 2)

def fibonacciEncoding(n):
	index = largestFiboLessOrEqual(n)

	codeword = ['a' for i in range(index + 2)]

	i = index

	while(n):
		codeword[i] = '1'
		n = n - fib[i]
		i -= 1

		while(i >= 0 and fib[i] > n):
			codeword[i] = '0'
			i -= 1

	codeword[index + 1] = '1'

	return "".join(codeword)

if __name__ == "__main__":
	n = 143
	print("Fibonacci code word for", n, " is ", fibonacciEncoding(n))
