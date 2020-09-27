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
const int MAX = 1e5 + 5;
int n, m;
int cats[MAX];
vector<int> adj[MAX];
bool visited[MAX];
int cnt;
void dfs(int v, int consecutive_cats) {
    visited[v] = 1;
    if(cats[v] == 1) {
        consecutive_cats++;
    } else {
        consecutive_cats = 0;
    }

    if(consecutive_cats > m) {
        return;
    }

    if(v != 1 && int(adj[v].size()) == 1) {
        cnt++;
    }

    for(int it : adj[v]) {
        if(!visited[it]) {
            dfs(it, consecutive_cats);
        }
    }
}

void solve() {
    cin >> n >> m;
    
    for(int i = 1;i <= n;i++) {
        sc(cats[i]);
    }

    int src, dest;
    for(int i = 1;i < n;i++) {
        cin >> src >> dest;
        adj[src].pb(dest);
        adj[dest].pb(src);
    }

    cnt = 0;
    dfs(1, 0);
    pf(cnt);
}

int main() {
    go();
    solve();
    return 0;
}