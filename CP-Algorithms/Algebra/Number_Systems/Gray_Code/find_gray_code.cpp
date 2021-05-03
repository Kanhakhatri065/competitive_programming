#include <bits/stdc++.h>

using namespace std;

int g(int n) {
	return n ^ (n >> 1);
}

int main() {
	int n;
	scanf("%d", &n);

	cout << "n : " << n << endl;
	cout << "gray code : " << g(n) << endl;

	return 0;
}
