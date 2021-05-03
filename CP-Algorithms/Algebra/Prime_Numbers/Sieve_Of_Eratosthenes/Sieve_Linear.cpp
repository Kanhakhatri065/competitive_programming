#include <bits/stdc++.h>

using namespace std;

const int N = 1e7;
int lp[N + 1];
vector<int> pr;

void computation() {
	memset(lp, 0, sizeof(lp));

	for(int i = 2;i <= N;i++) {
		if(lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}

		for(int j = 0;j < int(pr.size()) && pr[j] <= lp[i] && i * pr[j] <= N;j++) {
			lp[i * pr[j]] = pr[j];
		}
	}
}

int main() {
	computation();

	for(int p : pr) {
		if(p > 100) {
			break;
		}

		cout << p << " ";
	}
	cout << endl;

	return 0;
}
