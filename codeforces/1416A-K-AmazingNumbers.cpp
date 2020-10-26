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
const int N = 3e5 + 5;
int f[N], last[N], arr[N], ans[N];
int n;

void solve() {
	sc(n);
	for(int i = 1;i <= n;i++) {
		f[i] = last[i] = 0;
		ans[i] = -1;
	}

	for(int i = 1;i <= n;i++) {
		sc(arr[i]);
	}

	for(int i = 1;i <= n;i++) {
		int x = arr[i];
		f[x] = max(f[x], i - last[x]);
		last[x] = i;
	}

	for(int x = 1;x <= n;x++) {
		f[x] = max(f[x], n - last[x] + 1);
		for(int i = f[x];i <= n && ans[i] == -1;i++) {
			ans[i] = x;
		}
	}

	for(int i = 1;i <= n;i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}

int main() {
	int t;
	sc(t);

	while(t--) {
		solve();
	}

	return 0;
}
