#include <bits/stdc++.h>

using namespace std;

void range_mod_inverse(int m) {
	int inv[m];
	inv[1] = 1;
	for(int i = 2;i < m;i++) {
		inv[i] = m - (m / i) * inv[m % i] % m;
	}

	cout << "m : " << m << endl;
	for(int i = 1;i < 12;i++) {
		cout << "i : " << i << " mod_inv : " << inv[i] << endl;
	}
}

int main() {
	range_mod_inverse(12);
	return 0;
}
