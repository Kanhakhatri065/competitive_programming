#include <bits/stdc++.h>

using namespace std;

int fermat(int n) {
	int a = ceil(sqrt(n));
	int b2 = a * a - n;
	int b = round(sqrt(b2));
	while(b * b != b2) {
		a = a + 1;
		b2 = a * a - n;
		b = round(sqrt(b2));
	}

	return a - b;
}

int main() {
	int n = 15;
	int q = fermat(n);
	int p = n / q;

	cout << "n : " << n << " factors are : " << p << " and " << q << endl;
	return 0;
}
