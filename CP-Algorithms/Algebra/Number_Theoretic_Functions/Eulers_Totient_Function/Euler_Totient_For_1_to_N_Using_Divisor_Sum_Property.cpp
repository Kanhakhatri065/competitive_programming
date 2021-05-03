#include <bits/stdc++.h>

using namespace std;

void phi_1_to_n(int n) {
	vector<int> phi(n + 1);
	phi[0] = 1;
	phi[1] = 1;

	for(int i = 2;i <= n;i++) phi[i] = i - 1;

	for(int i = 2;i <= n;i++) {
		for(int j = 2 * i;j <= n;j += i) {
			phi[j] -= phi[i];
		}
	}

	for(int i = 1;i <= n;i++) {
		cout << i << " : " << phi[i] << endl;
	}
}

int main() {
	int n = 20;
	cout << "n : " << n << endl;
	phi_1_to_n(n);
	return 0;
}
