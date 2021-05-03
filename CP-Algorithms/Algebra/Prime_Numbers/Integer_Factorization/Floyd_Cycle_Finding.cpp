#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll mult(ll a, ll b, ll mod) {
	return (__int128)a * b % mod;
}

ll f(ll x, ll c, ll mod) {
	return (mult(x, x, mod) + c) % mod;
}


ll rho(ll n, ll x0 = 2, ll c = 1) {
	ll x = x0;
	ll y = x0;
	ll g = 1;
	while(g == 1) {
		x = f(x, c, n);
		y = f(y, c, n);
		y = f(y, c, n);

		g = __gcd(abs(x - y), n); 
	}

	return g;
}

int main() {
	int n = 2206637;
	cout << "n : " << n << endl;
	cout << "rho : " << rho(n) << endl;

	return 0;
}
