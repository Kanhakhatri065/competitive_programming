#include <bits/stdc++.h>

using namespace std;

int powmod(int a, int b, int p) {
	int res = 1;
	while(b) {
		if(b & 1) {
			res = (1LL * res * a) % p;
			b--;
		} else {
			a = (1LL * a * a) % p;
			b >>= 1;
		}
	}

	return res;
}

int generator(int p) {
	vector<int> fact;
	int phi = p - 1, n = phi;
	for(int i = 2;i * i <= n;i++) {
		if(n % i == 0) {
			fact.push_back(i);
			while(n % i == 0) {
				n /= i;
			}
		}
	}

	if(n > 1) {
		fact.push_back(n);
	}

	for(int res = 2;res <= p;res++) {
		bool ok = true;
		for(int fac : fact) {
			ok &= (powmod(res, phi / fac, p) != 1);
		}

		if(ok) return res;
	}

	return -1;
}

int main() {
	cout << "1 to 10" << endl;
	for(int i = 1;i <= 10;i++) {
		cout << "i : " << i << " primitive root mod i : " << generator(i) << endl;
	}
	return 0;
}
