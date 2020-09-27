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
typedef long double ld;
const int MAX = 2e5 + 15;
int n;
vector<int> g[MAX];
ld dfs(int v = 0, int p = -1){
	ld sum = 0;
	for(auto u : g[v])
		if(u != p)
			sum += dfs(u, v) + 1;
	return sum ? sum / (g[v].size() - (p != -1)) : 0;
}

void solve() {
    sc(n);

    int src, dest;
    for(int i = 1;i < n;i++) {
        cin >> src >> dest;
        src--, dest--;
        g[src].pb(dest);
        g[dest].pb(src);
    }

    cout << fixed << setprecision(7) << dfs() << endl;
}

int main() {
    go();
    solve();
    return 0;
}