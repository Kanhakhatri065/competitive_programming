#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a(n);
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
		sum += a[i].first;
	}
	
	sort(a.begin(), a.end(), [&](pair<int, int> a, pair<int, int> b) { return a.first - a.second > b.first - b.second; });
	
	for (int i = 0; i < n; ++i) {
		if (sum <= m) {
			cout << i << endl;
			return 0;
		}
		sum -= a[i].first - a[i].second;
	}
	
	if (sum <= m)
		cout << n << endl;
	else
		cout << -1 << endl;
	
	return 0;
}