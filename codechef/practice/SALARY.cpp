#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);

	vector<int> w(n);
	for(int i = 0;i < n;i++) {
		scanf("%d", &w[i]);
	}

	int sum = accumulate(w.begin(), w.end(), 0);
	int mn = *min_element(w.begin(), w.end());

	int ans = sum - n * mn;
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);

	while(t--) {
		solve();
	}

	return 0;
}
