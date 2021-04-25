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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
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
const int N = 505;
const int K = 12;
const ll INF = 1e18;
/*-------------- Push your limits here ---------------------------*/
ll dp[N][N][K];
ll r[N][N];
ll d[N][N];
void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0;i < n;i++) for(int j = 0;j + 1 < m;j++) cin >> r[i][j];
    for(int i = 0;i + 1 < n;i++) for(int j = 0;j < m;j++) cin >> d[i][j];

    for(int p = 1;p <= k / 2;p++) {
        for(int i = 0;i < n;i++) {
            for(int j = 0; j< m;j++) {
                dp[i][j][p] = INF;
                if(j + 1 < m) ckmin(dp[i][j][p], r[i][j] + dp[i][j + 1][p - 1]);
                if(j - 1 >= 0) ckmin(dp[i][j][p], r[i][j - 1] + dp[i][j - 1][p - 1]);
                if(i + 1 < n) ckmin(dp[i][j][p], d[i][j] + dp[i + 1][j][p - 1]);
                if(i - 1 >= 0) ckmin(dp[i][j][p], d[i - 1][j] + dp[i - 1][j][p - 1]);
            }
        }
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(k & 1) cout << (-1) << " ";
            else cout << (2LL * dp[i][j][k / 2]) << " ";
        }
        cout << endl;
    }
}

int main() {
    go();
    ssolve
    return 0;
}
