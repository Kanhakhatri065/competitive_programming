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
const int N = 2e5 + 5;
vector<int> graph[N];
vector<int> dist, sz;
int n, k;

void dfs(int u, int p) {
    dist[u] = dist[p] + 1;
    
    for(int v : graph[u]) {
        if(v == p) {
            continue;
        }

        dfs(v, u);
        sz[u] += sz[v];
    }
}

void solve() {
    cin >> n >> k;

    for(int i = 1;i < n;i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    sz.resize(n, 1);
    dist.resize(n, 0);

    dfs(0, 0);

    for(int i = 0;i < n;i++) {
        dist[i] -= sz[i];
    }

    sort(all(dist));

    ll ans = 0;
    while(k > 0) {
        ans += dist.back();
        dist.pop_back();
        k--;
    }

    pf(ans);
}

int main() {
    go();
    solve();
    return 0;
}