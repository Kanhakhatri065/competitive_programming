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
const int inf = 1e18;
void solve() {
	int n, a, b;
	cin >> n >> a >> b;

	string s;
	sc(s);

	vector<int> v(n);
	for(int i = 0;i < n;i++) {
		v[i] = s[i] - '0';
	}

	int dp[2][n + 1];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = b;
	dp[1][0] = inf;

	for(int i = 1;i <= n;i++) {
		dp[0][i] = b;
		dp[1][i] = 2 * b;
		int ht = v[i - 1];

		if(i != n && v[i]) ht = 1;
		if(ht) {
			dp[0][i] = inf;
		} else {
			dp[0][i] += min(dp[1][i - 1] + 2 * a, dp[0][i - 1] + a);
		}

		dp[1][i] += min(dp[1][i - 1] + a, dp[0][i - 1] + 2 * a);
	}

	pf(dp[0][n]);
}

int32_t main() {
	int t;
	sc(t);

	while(t--) {
		solve();
	}

	return 0;
}
