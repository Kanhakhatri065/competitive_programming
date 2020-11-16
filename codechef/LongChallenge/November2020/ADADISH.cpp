/*
	I love the sound you make when you shut up.
*/
#include <bits/stdc++.h>
using namespace std;

void go() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

typedef long long ll;

void solve() {
	int n;
	cin >> n;

	vector<int> v(n);
	for(int i = 0;i < n;i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), greater<int>());

	int f = 0, s = 0;
	for(int i = 0;i < n;i++) {
		if(f < s) {
			f += v[i];
		} else {
			s += v[i];
		}
	}
	
	cout << max(f, s) << endl;
}

int main() {
	go();
	int t;
	cin >> t;

	while(t--) {
		solve();
	}

	return 0;
}