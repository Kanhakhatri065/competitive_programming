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
const int N = 2e5 + 5;
/*-------------- Push your limits here ---------------------------*/
void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    int arr[n + 1][m + 1];
    for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) cin >> arr[i][j];

    ll mn = min(n, m), mx = max(n, m);
    ll ans = 0;

    ll prefixSum[n + 1][m + 1];
    mem(prefixSum, 0LL);
    for(int i = 1;i <= m;i++) prefixSum[1][i] = prefixSum[1][i - 1] + arr[1][i];
    for(int i = 1;i <= n;i++) prefixSum[i][1] = prefixSum[i - 1][1] + arr[i][1];

    for(int i = 2;i <= n;i++) {
        for(int j = 2;j <= m;j++) {
            prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1]
             - prefixSum[i - 1][j - 1] + arr[i][j];
        }
    }

    for(int l = 1;l <= mn;l++) {
        for(int i = l;i <= n;i++) {
            for(int j = l;j <= m;j++) {
                ll tmp = prefixSum[i][j] - prefixSum[i - l][j]
                 - prefixSum[i][j - l] + prefixSum[i - l][j - l];
                if(tmp >= (1LL * l * l * k)) ans++;
            }
        }
    }

    pf(ans);
}

int main() {
    go();
    msolve
    return 0;
}
