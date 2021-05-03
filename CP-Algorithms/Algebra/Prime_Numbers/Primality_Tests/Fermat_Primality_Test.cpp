#include <bits/stdc++.h>

using namespace std;

int binpow(int a, int b, int n) {
	int res = 1;
	while(b) {
		if(b & 1) {
			res = res * a % n;
		}

		a = a * a % n;
		b >>= 1;
	}

	return res;
}

bool probablyPrimeFermat(int n, int iter = 5) {
	if(n < 4) {
		return n == 2 || n == 3;
	}

	for(int i = 0;i < iter;i++) {
		int a = 2 + rand() % (n - 3);
		if(binpow(a, n - 1, n) != 1) {
			return false;
		}
	}

	return true;
}

int main() {
	int n = 23;
	cout << "n : " << n << " " << (probablyPrimeFermat(n) ? " is probably prime" : " not prime") << endl;

	n = 25;
	cout << "n : " << n << " " << (probablyPrimeFermat(n) ? " is probably prime" : " not prime") << endl;

	return 0;
}
