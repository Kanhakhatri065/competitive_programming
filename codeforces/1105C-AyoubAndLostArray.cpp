/*** I came, I saw, I conquered. ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef unsigned long long ull;
#define sc(a) cin >> a
#define pf(a) cout << a << endl
#define forIn(arr, num) for(ll i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
#define mod 1000000007
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
void go() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
/*----------------------------------------------------------------*/
#define int long long 
const int N = 2e5 + 5, MOD = 1e9 + 7;
int dp[N][3];
void solve() {
	int n, l, r;
	cin >> n >> l >> r;

	int c[3] = {0};
	for(int k = l;k < min(r + 1, l + 3);k++) {
		c[k % 3] = 1 + (r - k) / 3;
	}

	dp[0][0] = 1;
	for(int k = 1;k <= n;k++) {
		for(int j = 0;j < 3;j++) {
			for(int i = 0;i < 3;i++) {
				dp[k][(i + j) % 3] = (dp[k][(i + j) % 3] + 1LL * dp[k - 1][i] * c[j]) % MOD;
			}
		}
	}

	pf(dp[n][0]);
}

int32_t main() {
	solve();
	return 0;
}
