#include <bits/stdc++.h>

using namespace std;

int powmod(int a, int b, int m) {
	int res = 1;
	while(b) {
		if(b & 1) {
			res = (1LL * res * a) % m;
		}

		a = (1LL * a * a) % m;
		b >>= 1;
	}

	return res;
}

int solve(int a, int b, int m) {
	a %= m;
	b %= m;

	int n = ceil(sqrt(m));
	map<int, int> vals;

	for(int p = 1;p <= n;p++) {
		vals[powmod(a, p * n, m)] = p;
	}

	for(int q = 0;q <= n;q++) {
		int cur = (1LL * powmod(a, q, m) * b) % m;
		if(vals.count(cur)) {
			int ans = vals[cur] * n - q;
			return ans;
		}
	}

	return -1;
}

int main() {
	int a = 7, b = 5, m = 10;
	cout << "a : " << a << " b : " << b << " m : " << m << endl;
	cout << "x for a ^ x = b (mod m) : " << solve(a, b, m) << endl;
	return 0;
}
