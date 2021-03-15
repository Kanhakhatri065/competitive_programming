/*
    I love the sound you make when you shut up.
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
/*-------typedefs------*/
template<class T> using ordered_set = tree<T, null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update> ;
using ll = long long;
using pi = pair<int, int>;
/*-----in and out--------*/
#define pf(a) cout << a << endl
#define forIn(arr, num) for(int i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(int i = 0; i < int(ans.size()); i++) cout << ans[i] << (i + 1 < int(ans.size()) ? ' ' : '\n');
/*---useful defines------*/
#define sz(x) (int)(x).size()
#define pb push_back
#define mem(a, b) memset(a,(b), sizeof(a))
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
/*----- the binary answer of life-----*/
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
/*---checking and pushing-----*/
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
/*---- FAST I/O and file read ---*/
void go() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
}
/*-------- test-case stuff--------------*/
#define ssolve solve();
#define msolve int T;cin >> T;while(T--) {solve();}
#define mcsolve int T;cin >> T;for(int tt = 1;tt <= T;tt++) {cout << "Case #" << tt << ": ";solve();}
/*-------- movement in a 2D array ------*/
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
/*----------------------------------------------------------------*/
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
/*-------------- Push your limits here ---------------------------*/
int n, m, scc, comp[2 * N], visited[2 * N];
char ans[N];
vector<int> adj[2][2 * N];
vector<int> dfn;
void dfs(int u, int t) {
    visited[u] = 1;
    if(t == 1) comp[u] = scc;
    for(int v : adj[t][u]) {
        if(!visited[v]) dfs(v, t);
    }

    if(t == 0) dfn.push_back(u);
}

void solve() {
    cin >> n >> m;
    for(int i = 0;i < n;i++) {
        int u1, u2;
        char c1, c2;
        cin >> c1 >> u1 >> c2 >> u2;

        u1 *= 2, u2 *= 2;
        if(c1 == '-') u1 ^= 1;
        if(c2 == '-') u2 ^= 1;
        adj[0][u1 ^ 1].pb(u2);
        adj[0][u2 ^ 1].pb(u1);
        adj[1][u1].pb(u2 ^ 1);
        adj[1][u2].pb(u1 ^ 1);
    }

    for(int i = 1;i <= 2 * m;i++) {
        if(!visited[i]) dfs(i, 0);
    }

    mem(visited, 0);
    for(int i = 2 * m - 1;i >= 0;i--) {
        if(!visited[dfn[i]]) {
            scc++;
            dfs(dfn[i], 1);
        }
    }

    for(int i = 1;i <= m;i++) {
        if(comp[2 * i] == comp[2 * i + 1]) {
            pf("IMPOSSIBLE");
            return;
        }

        ans[i] = (comp[2 * i] > comp[2 * i + 1]) ? '+' : '-';
    }

    for(int i = 1;i <= m;i++) cout << ans[i];
    cout << endl;
}

int main() {
    go();
    ssolve
    return 0;
}
