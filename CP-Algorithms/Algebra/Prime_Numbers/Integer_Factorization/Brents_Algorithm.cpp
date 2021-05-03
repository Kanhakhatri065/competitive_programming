#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll mult(ll a, ll b, ll mod) {
	return (__int128)a * b % mod;
}

ll f(ll x, ll c, ll mod) {
	return (mult(x, x, mod) + c) % mod;
}

ll brent(ll n, ll x0 = 2, ll c = 1) {
	ll x = x0;
	ll g = 1;
	ll q = 1;
	ll xs, y;

	int m = 128;
	int l = 1;

	while(g == 1) {
		y = x;

		for(int i = 1;i < l;i++) {
			x = f(x, c, n);
		}

		int k = 0;
		while(k < l && g == 1) {
			xs = x;
			for(int i = 0;i < m && i < l - k;i++) {
				x = f(x, c, n);
				q = mult(q, abs(y - x), n);
			}

			g = __gcd(q, n);
			k += m;
		}

		l *= 2;
	}

	if(g == n) {
		do {
			xs = f(xs, c, n);
			g = __gcd(abs(xs - y), n);
		} while(g == 1);
	}	

	return g;
}

int main() {
	int n = 256;
	cout << "n : " << n << endl;
	cout << "factor : " << brent(n) << endl;
	return 0;
}