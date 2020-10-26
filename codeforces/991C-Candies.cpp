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
bool check(int k, int n) {
	int sum = 0;
	int cur = n;
	while(cur > 0) {
		int o = min(cur, k);
		sum += o;
		cur -= o;
		cur -= cur / 10;
	}

	return sum * 2 >= n;
}

void solve() {
	int n;
	cin >> n;

	int l = 1, r = n;
	int ans = r;
	while(l <= r) {
		int k = (l + r) / 2;
		if(check(k, n)) {
			ans = k;
			r = k - 1;
		} else {
			l = k + 1;
		}
	}

	pf(ans);
}

int32_t main() {
	solve();
	return 0;
}
