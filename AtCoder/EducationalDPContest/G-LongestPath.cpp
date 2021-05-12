#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pf(a) cout << a << endl
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
void go() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
}
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
vector<int> adj[N];
int dp[N];
int ans;
int dfs(int u) {
    if(dp[u]) return dp[u];
    for(int v : adj[u]) {
        ckmax(dp[u], dfs(v) + 1);
    }
    return dp[u];
}

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }

    memset(dp, 0, sizeof(dp));
    ans = 0;
    for(int i = 1;i <= n;i++) if(!dp[i]) dfs(i);
    for(int i = 1;i <= n;i++) ckmax(ans, dp[i]);
    pf(ans);
}

int main() {
    go();
    int t;t = 1;
    while(t--) solve();
    return 0;
}
