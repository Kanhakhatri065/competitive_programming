#include <bits/stdc++.h>

using namespace std;

void solve() {
   	int n, k;
  	scanf("%d%d", &n, &k); 

	string a, b;
	cin >> a >> b;

	int have[27] = {0};
	int need[27] = {0};

	for(int i = 0;i < n;i++) {
		have[a[i] - 'a']++;
		need[b[i] - 'a']++;
	}

	bool flag = true;
	for(int i = 0;i < 26;i++) {
		if(have[i] < need[i] || (have[i] -= need[i]) % k) {
			flag = false;
		}

		have[i + 1] += have[i];
	}

	cout << (flag ? "YES" : "NO") << endl;
}

int main() {
    int t;
    scanf("%d", &t);
    
    while(t--) {
        solve();
    }

    return 0;
}
