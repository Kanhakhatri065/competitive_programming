#include <bits/stdc++.h>

using namespace std;

int extended_euclidean(int a, int b, int &x, int &y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	int x1, y1;
	int d = extended_euclidean(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

void mod_inv(int a, int m) {
	int g, x, y;
	g = extended_euclidean(a, m, x, y);

	if(g != 1) {
		cout << "No solutin!" << endl;
	} else {
		x = (x % m + m) % m;
		cout << "inv : " << x << endl;
	}
}

int main() {
	int a = 7, m = 12;
	mod_inv(a, m);
	return 0;
}
