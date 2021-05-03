#include <bits/stdc++.h>

using namespace std;

//simple method using a direct recursive implementation
int fib_using_simple_recursion(int n) {
	if(n <= 1) return n;
	return fib_using_simple_recursion(n - 1) + fib_using_simple_recursion(n - 2);
}

//using dynamic programming O(n)
int fib_using_dynamic_programming(int n) {
	int f[n + 2];
	
	f[0] = 0;
	f[1] = 1;

	for(int i = 2;i <= n;i++) {
		f[i] = f[i - 1] + f[i - 2];
	}

	return f[n];
}

// using variables O(n)
int fib_using_variables(int n) {
	int a = 0, b = 1, c;

	if(n == 0) {
		return a;
	}

	for(int i = 2;i <= n;i++) {
		c = a + b;
		a = b;
		b = c;
	}

	return b;
}

//using matrix exponentiation O(n)
void multiply(int F[2][2], int M[2][2]);
void power(int F[2][2], int n);

int fib_using_matrix(int n) {
	int F[2][2] = {{1, 1}, {1, 0}};

	if(n == 0) {
		return 0;
	}

	power(F, n - 1);

	return F[0][9];
}

void multiply(int F[2][2], int M[2][2]) {
	int x = F[0][0] * M[0][0] + F[0][1] * M[0][1];
	int y = F[0][0] * M[1][0] + F[0][1] * M[1][1];
	int z = F[1][0] * M[0][0] + F[1][1] * M[0][1];
	int w = F[1][0] * M[1][0] + F[1][1] * M[1][1];

	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;	
}

void power(int F[2][2], int n) {
	int M[2][2] = {{1, 1}, {1, 0}};

	for(int i = 2;i <= n;i++) {
		multiply(F, M);
	}
}

void power_log(int F[2][2], int n);
//using matrix exponentiation O(logn)
int fib_using_matrix_log(int n) {
	int F[2][2] = {{1, 1}, {1, 0}};
	
	if(n == 0) {
		return 0;
	}

	power_log(F, n - 1);
	return F[0][0];
}

void multiply_log(int F[2][2], int M[2][2]) {
	int x = F[0][0] * M[0][0] + F[0][1] * M[0][1];
    int y = F[0][0] * M[1][0] + F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] + F[1][1] * M[0][1];
    int w = F[1][0] * M[1][0] + F[1][1] * M[1][1];
  
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w; 
}

void power_log(int F[2][2], int n) {
	if(n == 0 || n == 1) {
		return;
	}	

	int M[2][2] = {{1, 1}, {1, 0}};

	power_log(F, n / 2);
	multiply(F, F);

	if(n & 1) {
		multiply(F, M);
	}
}

//using formula O(1)
int fib_using_formula(int n) {
	double phi = (1 + sqrt(5)) / 2;
	return round(pow(phi, n) / sqrt(5));
}

int main() {
	int n = 9;
	
	cout << " n : " << n << endl;
	cout << fib_using_simple_recursion(n) << " using simple recursion." << endl;
	cout << fib_using_dynamic_programming(n) << "using dynamic programming." << endl;
	cout << fib_using_variables(n) << " using variables." << endl;
	cout << fib_using_matrix(n) << " using matrix O(n)" << endl;
	cout << fib_using_matrix_log(n) << " using matrix exponentiation O(logn)" << endl;
	cout << fib_using_formula(n) << " using formula O(1)" << endl;
	
	return 0;
}
