#include <bits/stdc++.h>

using namespace std;

pair<int, int> fib(int n) {
	if(n == 0) return {0, 1};

	auto p = fib(n >> 1);
	int c = p.first * (2 * p.second - p.first);
	int d = p.first * p.first + p.second * p.second;

	if(n & 1) return {d, c + d};
	return {c, d};
}

int main() {
	int n = 9;
	
	cout << "n : " << n << endl;
	auto p = fib(n);
	cout << "C : " << p.first << " D : " << p.second << endl;
	cout << "Fibonacci : " << p.first << endl;

	return 0;
}
