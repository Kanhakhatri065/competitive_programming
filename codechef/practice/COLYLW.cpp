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

bool good(int mid, int r, int g, int b) {
	return ((r - mid) + (b - mid) + g) >= mid;
}

int color(int n, int r, int g, int b) {
	int left = 0;
	int right = min({n, r, b});

	int ans = 0;
	while(left <= right) {
		int mid = (left + right) / 2;

		if(good(mid, r, g, b)) {
			ans = mid;
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	return ans;
}

void solve() {
	int n, r, g, b;
	cin >> n >> r >> g >> b;

	pf(color(n, r, g, b));
}

int32_t main() {
	int t;
	sc(t);

	while(t--) {
		solve();
	}

	return 0;
}
