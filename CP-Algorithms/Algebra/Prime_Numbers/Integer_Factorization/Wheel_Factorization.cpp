#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> wheel_factorization(ll n) {
	vector<ll> factorization;

	while(n % 2 == 0) {
		factorization.push_back(2);
		n /= 2;
	}

	for(ll d = 3;d * d <= n;d += 2) {
		while(n % d == 0) {
			factorization.push_back(d);
			n /= d;
		}
	}

	if(n > 1) {
		factorization.push_back(n);
	}

	return factorization;
}

int main() {
	ll n = 500102;
	cout << "Factorization of " << n  << endl;
	vector<ll> factors = wheel_factorization(n);
	for(ll p : factors) {
		cout << p << " ";
	}

	cout << endl;

	return 0;
}
