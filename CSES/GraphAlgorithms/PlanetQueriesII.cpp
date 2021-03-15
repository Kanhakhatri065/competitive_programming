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
const int N = 2e5 + 5;
const int P = 30;
/*-------------- Push your limits here ---------------------------*/
int n, q;
int dp[N][P];
int dep[N], cy[N];

void dfs(int u, int t = 0) {
    int v = dp[u][0];
    cy[u] = --t;
    if (!cy[v]) dfs(v, t);
    if (cy[v] < 0) { // detect a cycle
        cy[u] = cy[v] - cy[u] + 1;
        dep[u] = 0; // make u the root
    }
    else {
        cy[u] = cy[v];
        dep[u] = dep[v] + 1;
    } 
}

int ancestor(int u, int k) {
    for(int i = 0;i < P;i++) {
        if(k & (1 << i)) {
            u = dp[u][i];
        }
    }

    return u;
}

void solve() {
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> dp[i][0];

    for(int i = 1;i < P;i++) {
        for(int u = 1;u <= n;u++) {
            dp[u][i] = dp[dp[u][i - 1]][i - 1];
        }
    }

    for(int i = 1;i <= n;i++) {
        if(!cy[i]) dfs(i);
    }

    while(q--) {
        int u, v;
        cin >> u >> v;

        if(dep[v] <= dep[u] && ancestor(u, dep[u] - dep[v]) == v) { // directly reaching v
            pf(dep[u] - dep[v]);
        } else if(dep[v] <= dep[u] + cy[u] && ancestor(u, dep[u] - dep[v] + cy[v]) == v) {// use the cycle to reach v
            pf(dep[u] - dep[v] + cy[v]);
        } else {
            pf(-1);
        }
    }
}

int main() {
    go();
    ssolve
    return 0;
}
