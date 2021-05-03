#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b, int m) {
	a %= m;
	b %= m;

	int n = sqrt(m) + 1;
	int an = 1;

	for(int i = 0;i < n;i++) {
		an = (1LL * an * a) % m;
	}

	unordered_map<int, int> vals;
	for(int q = 0, cur = b;q <= n;q++) {
		vals[cur] = q;
		cur = (1LL * cur * a) % m;
	}

	for(int p = 1, cur = 1;p <= n;p++) {
		cur = (1LL * cur * an) % m;
		if(vals.count(cur)) {
			int ans = n * p - vals[cur];
			return ans;
		}
	}

	return -1;
}

int main() {
	int a = 7, b = 8, m = 15;
	cout << "a : " << a << " b : " << b << " m : " << m << endl;
	cout << "x for a^x = b (mod m) : " << solve(a, b, m) << endl;
	return 0;
}
