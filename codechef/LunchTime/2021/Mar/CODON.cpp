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
#define int long long
const int MOD = 1e9 + 7;
const int N = 1e3 + 5;
/*-------------- Push your limits here ---------------------------*/
int n, m, l;
string s, c;
int tmp[N];
vector<int> adj[N];
int p[N];
int cntEdges[N][N];
int dp[N][N];
int pow_mod(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        y >>= 1;
    }

    return res;
}

void reset() {
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            cntEdges[i][j] = 0;
        }
        adj[i].clear();
    }

    for(int i = 1;i <= l;i++) {
        for(int j = 1;j <= n;j++) {
            dp[i][j] = 0;
        }
    }
}

void solve() {
    cin >> n >> m >> l;
    cin >> s >> c;

    for(int i = 1;i <= m;i++) cin >> tmp[i];
    for(int i = 1;i <= m;i++) {
        int u = tmp[i], v;
        cin >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        if(u > v) swap(u, v);
        cntEdges[u][v]++;
    }

    s = ' ' + s;
    c = ' ' + c;

    for(int u = 1;u <= n;u++) {
        if(s[1] == c[u]) dp[1][u] = 1;
    }

    for(int i = 2;i <= l;i++) {
        for(int u = 1;u <= n;u++) {
            if(s[i] == c[u]) {
                for(int v : adj[u]) {
                    dp[i][u] = (dp[i][u] + dp[i - 1][v]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for(int u = 1;u <= n;u++) {
        ans = (ans + dp[l][u]) % MOD;
    }

    int same = 1;
    for(int i = 2;i < sz(s);i++) {
        if(s[i] != s[1]) {
            same = 0;
            break;
        }
    }

    if(same) {
        for(int i = 0;i <= m;i++) {
            p[i] = pow_mod(i, l - 1);
        }

        for(int u = 1;u <= n;u++) {
            if(c[u] != s[1]) continue;
            for(int v = u + 1;v <= n;v++) {
                if(c[v] != s[1]) continue;
                ans -= p[cntEdges[u][v]];
                if(ans < 0) ans += MOD;
            }
        }
    }

    pf(ans);
    reset();
}

int32_t main() {
    go();
    msolve
    return 0;
}
