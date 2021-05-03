#include <bits/stdc++.h>

using namespace std;

// returns minimum x for which a ^ x % m = b % m
int solve(int a, int b, int m) {
	a %= m;
	b %= m;
	
	int k = 1, add = 0, g;
	while((g = __gcd(a, m)) > 1) {
		if(b == k) return add;

		if(b % g) return -1;

		b /= g, m /= g, add++;
		k = (1LL * k * (a / g)) % m;
	}

	int n = sqrt(m) + 1;
	int an = 1;
	for(int i = 0;i < n;i++) an = (1LL * an * a) % m;

	unordered_map<int, int> vals;
	for(int q = 0, cur = b;q <= n;q++) {
		vals[cur] = q;
		cur = (1LL * cur * a) % m;
	}

	for(int p = 1, cur = k;p <= n;p++) {
		cur = (1LL * cur * an) % m;
		if(vals.count(cur)) {
			int ans = n * p - vals[cur] + add;
			return ans;
		}
	}

	return -1;
}

int main() {
	int a = 10, b = 1, m = 100;
	cout << "a : " << a << " b : " << b << " m : " << m << endl;
	cout << "min x for a ^ x % m = b % m : " << solve(a, b, m) << endl; 
	return 0;
}
