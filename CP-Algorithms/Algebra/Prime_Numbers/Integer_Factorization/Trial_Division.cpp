#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> trial_divison(ll n) {
	vector<ll> factorization;
	for(ll d = 2;d * d <= n;d++) {
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
	ll n = 400;

	vector<ll> factors = trial_divison(n);
	cout << "Factorization of : " << n << endl;
	for(ll x : factors) {
		cout << x << " ";
	}

	cout << endl;
	return 0;
}
