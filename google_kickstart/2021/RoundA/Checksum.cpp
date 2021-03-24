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
/*-------------- Push your limits here ---------------------------*/
int n;
int board[N][N];
int cost[N][N];
int rv[N], cv[N];

vector<pair<int, pi>> v;
int par[2 * N];

int find_set(int x) {
    if(x == par[x]) return x;
    return par[x] = find_set(par[x]);
}

bool union_set(int x, int y) {
    x = find_set(x), y = find_set(y);
    if(x == y) return false;
    par[x] = y;
    return true;
}

void solve() {
    cin >> n;

    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) cin >> board[i][j];

    v.clear();
    for(int i = 0;i < 2 * n;i++) par[i] = i;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cin >> cost[i][j];
            v.push_back({cost[i][j], {i, j + n}});
        }
    }

    for(int i = 0;i < n;i++) cin >> rv[i];
    for(int i = 0;i < n;i++) cin >> cv[i];

    sort(all(v));
    reverse(all(v));

    int ans = 0;
    for(auto x : v) {
        int a = x.ss.ff, b = x.ss.ss;
        if(!union_set(a, b)) {
            ans += x.ff;
        }
    }

    pf(ans);
}

int main() {
    go();
    mcsolve
    return 0;
}
