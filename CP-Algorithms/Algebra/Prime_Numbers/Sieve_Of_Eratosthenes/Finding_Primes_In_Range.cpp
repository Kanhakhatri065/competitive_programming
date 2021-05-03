#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<bool> segmentedSieve(ll L, ll R) {
	ll lim = sqrt(R);

	vector<bool> mark(lim + 1, false);
	vector<ll> primes;
	for(ll i = 2;i <= lim;i++) {
		if(!mark[i]) {
			primes.push_back(i);
			for(ll j = i * i;j <= lim;j += i) mark[j] = true;
		}
	}

	vector<bool> isPrime(R - L + 1, true);
	for(ll i : primes) {
		for(ll j = max(i * i, (L + i - 1) / (i * i));j <= R;j += i) {
			isPrime[j - L] = false;
		}
	}

	if(L == 1) isPrime[0] = false;

	return isPrime;
}

int main() {

	ll l = 1, r = 20;
	cout << "l : " << l << " r : " << r << endl;
	vector<bool> sieve = segmentedSieve(l, r);
	for(int i = l;i <= r;i++) {
		cout << i << (!sieve[i] ? " is prime" : " not prime") << endl;
	}
	return 0;
}
