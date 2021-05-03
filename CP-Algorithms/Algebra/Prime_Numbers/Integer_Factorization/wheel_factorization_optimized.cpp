#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> wheel_factorization(ll n) {
	vector<ll> factorization;

	for(ll d : {2LL, 3LL, 5LL}) {
		while(n % d == 0) {
			factorization.push_back(d);
			n /= d;
		}
	}

	static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};

	int i = 0;
	for(ll d = 7;d * d <= n;d += increments[i++]) {
		while(n % d == 0) {
			factorization.push_back(d);
			n /= d;
		}

		if(i == 8) {
			i = 0;
		}
	}

	if(n > 1) {
		factorization.push_back(n);
	}

	return factorization;
}

int main() {
	ll n = 1024 * 25 * 9;
	vector<ll> factors = wheel_factorization(n);
	cout << "Factorization of : " << n << endl;
	for(ll p :  factors) {
		cout << p << " ";
	}
	cout << endl;

	return 0;
}
