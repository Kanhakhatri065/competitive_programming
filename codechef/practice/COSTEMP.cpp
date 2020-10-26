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
vector<vector<int>> adj;
int n;
vector<int> ans, down, num;

void calc_down(int i = 0, int pr = -1) {
	down[i] = 0;
	num[i] = 0;
	for(int v : adj[i]) {
		if(v == pr) {
			continue;
		}

		calc_down(v, i);
		down[i] += (down[v] + num[v]);
		num[i] += num[v];
	}

	num[i] += 1;
}

void calc_ans(int i = 0, int pr = -1) {
	if(i == 0) {
		ans[i] = down[i];
	} else {
		ans[i] = ans[pr] + n - 2 * num[i];
	}
	
	for(int v : adj[i]) {
		if(v == pr) {
			continue;
		}

		calc_ans(v, i);
	}
}

void solve() {
	cin >> n;
	adj.resize(n);
	for(int i = 1;i < n;i++) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	ans.resize(n);
	num.resize(n);
	down.resize(n);
	
	calc_down();
	calc_ans();

	vpnt(ans);
}

int main() {
	solve();
	return 0;
}
