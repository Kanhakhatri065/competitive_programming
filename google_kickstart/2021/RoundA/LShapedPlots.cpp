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
const int N = 1005;
/*-------------- Push your limits here ---------------------------*/
int v[N][N];
int ps[N][N][4];
void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) cin >> v[i][j];

    for(int i = 0;i < N;i++) for(int j = 0;j < N;j++) for(int k = 0;k < 4;k++) ps[i][j][k] = 0;

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(v[i][j]) {
                ps[i][j][0] = 1 + ps[i - 1][j][0];
                ps[i][j][2] = 1 + ps[i][j - 1][2];
            }
        }
    }

    for(int i = n;i >= 1;i--) {
        for(int j = m;j >= 1;j--) {
            if(v[i][j]) {
                ps[i][j][1] = 1 + ps[i + 1][j][1];
                ps[i][j][3] = 1 + ps[i][j + 1][3];
            }
        }
    }

    int ans = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            for(int k = 0;k < 2;k++) {
                for(int l = 2;l < 4;l++) {
                    int x = ps[i][j][k];
                    int y = ps[i][j][l];

                    ans += max(0, (min(x, y / 2) - 1));
                    ans += max(0, (min(y, x / 2) - 1));
                }
            }
        }
    }

    pf(ans);
}

int main() {
    go();
    mcsolve
    return 0;
}
