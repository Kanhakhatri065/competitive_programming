#include <bits/stdc++.h>

using namespace std;

int rev_g(int g) {
	int n = 0;
	for(;g;g >>= 1) {
		n ^= g;
	}

	return n;
}

int main() {
	int g;
	scanf("%d", &g);

	cout << "g : " << g << endl;
	cout << "Inverse gray code : " << rev_g(g) << endl;
	return 0;
}
