#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const int N = 1e5 + 5;

ll a[N], dp[N];
int n, q;
ll r, ans;
void solve() {
	scanf("%d", &n);
	
	int one_pos = 0;
	for(int i = 1;i <= n;i++) {
		scanf("%lld", &a[i]);
		if(a[i] == 1) {
			one_pos = i;
		}
	}

	dp[0] = 0LL; 
	if(one_pos == 0 || one_pos == n) {
		for(int i = 1;i <= n;i++) {
			dp[i] = dp[i - 1];
			if(i == n) {
				dp[i] += (a[i] & 1) ? a[i] : (a[i] - 1);
			} else {
				dp[i] += (a[i] & 1) ? (a[i] - 1) : a[i];
			}
		}
	} else if(one_pos == 1) {
		dp[1] = 1;
		for(int i = 2;i <= n;i++) {
			dp[i] = dp[i - 1];
		}
	} else {
		for(int i = 1;i <= n;i++) {
			dp[i] = dp[i - 1];
			if(i == n) {
				dp[i] += (a[i] & 1) ? a[i] : (a[i] - 1);
			} else {
				if(a[i] != 1) {
					if(i + 1 == one_pos) {
						dp[i] += (a[i] & 1) ? a[i] : (a[i] - 1);
					} else {
						dp[i] += (a[i] & 1) ? (a[i] - 1) : a[i];
					}
				}
			}
		}
	}

	scanf("%d", &q);
	while(q--) {
		scanf("%lld", &r);
		r %= MOD;
		ans = ((r / n) * (dp[n] % MOD)) % MOD;
		if(r % n) {
			if(one_pos == 0) {
				if(a[r % n] & 1) {
					ans = (ans + dp[r % n] + 1) % MOD;
				} else {
					ans = (ans + dp[r % n]) % MOD;
				}
			} else if(one_pos == 1) {
				if(r == 1) {
					ans = 1;
				}

				if((r % n) > 1) {
					ans = (ans + 1) % MOD;
				}
			} else if(one_pos == n) {
				if(a[r % n] & 1) {
					ans = (ans + dp[r % n] + 1) % MOD;
				} else {
					ans = (ans + dp[r % n]) % MOD;
				}
			} else {
				if((r % n) == one_pos) {
					if(a[(r % n) - 1] % 2 == 0) {
						ans = (ans + dp[r % n] + 2) % MOD;
					} else {
						ans = (ans + dp[r % n]) % MOD;
					}
				} else if((r % n) + 1 == one_pos) {
					if(a[r % n] % 2 == 0) {
						ans = (ans + dp[r % n] + 1) % MOD;
					} else {
						ans = (ans + dp[r % n]) % MOD;
					}
				} else {
					if(a[r % n] & 1) {
						ans = (ans + dp[r % n] + 1) % MOD;
					} else {
						ans = (ans + dp[r % n]) % MOD;
					}
				}
			}
		} else {
			if(one_pos == 1) {
				//nothin much
			} else {
				if(a[n] % 2 == 0) {
					ans = (ans + 1) % MOD;
				}
			}
		}

		printf("%lld\n", ans);
	}
}

int main() {
	int t;
	scanf("%d", &t);

	while(t--) {
		solve();
	}

	return 0;
}
