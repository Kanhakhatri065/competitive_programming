#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAX = 1e7;

vector<ll> primes;

bool sieve[MAX];
void computation() {
	memset(sieve, true, sizeof(sieve));

	sieve[0] = sieve[1] = false;

	for(int i = 2;i < MAX;i++) {
		if(sieve[i]) {
			primes.push_back(i);
			for(int j = 2 * i;j < MAX;j += i) sieve[j] = false;
		}
	}
}

vector<ll> wheel_factorization(ll n) {
	vector<ll> factorization;
	for(ll d : primes) {
		if(d * d > n) {
			break;
		}

		while(n % d == 0) {
			factorization.push_back(d);
			n /= d;
		}
	}

	if(n > 1) factorization.push_back(n);

	return factorization;
}

int main() {
	ll n = 12 * 81;
	computation();

	vector<ll> factors = wheel_factorization(n);
	cout << "Factors of " << n << endl;
	for(ll p : factors) {
		cout << p << " ";
	}
	cout << endl;

	return 0;
}
