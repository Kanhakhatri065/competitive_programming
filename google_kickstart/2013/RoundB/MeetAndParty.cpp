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
const int N = 1010;
/*-------------- Push your limits here ---------------------------*/
int b;
int re[N][4];
ll calculateDistance(int tm, int tx, int ty) {
    ll dist = 0;
    for(int i = 0;i < b;i++) {
        ll x1, y1, x2, y2, x1c, y1c, x2c,y2c, sx1, sx2, sy1, sy2;
        x1 = re[i][0];
        y1 = re[i][1];
        x2 = re[i][2];
        y2 = re[i][3];
        x1c = tx - x1;
        y1c = ty - y1;
        x2c = x2 - tx;
        y2c = y2 - ty;
        sx1 = (x1c >= 0) ? 1 : -1;
        sx2 = (x2c >= 0) ? 1 : -1;
        sy1 = (y1c >= 0) ? 1 : -1;
        sy2 = (y2c >= 0) ? 1 : -1;

        dist += (y2 - y1 + 1) * (sx1 * (1 + x1c) * x1c + sx2 * (1 + x2c) * x2c) / 2;
        dist += (x2 - x1 + 1) * (sy1 * (1 + y1c) * y1c + sy2 * (1 + y2c) * y2c) / 2;
    }

    return dist;
}

void solve() {
    cin >> b;
    for(int i = 0;i < b;i++) for(int j = 0;j < 4;j++) cin >> re[i][j];
    
    int x, y;
    ll d = -1;
    for(int i = 0;i < b;i++) {
        int x1 = re[i][0];
        int y1 = re[i][1];
        int x2 = re[i][2];
        int y2 = re[i][3];

        ll tmp;
        for(int j = x1;j <= x2;j++) {
            for(int k = y1;k <= y2;k++) {
                tmp = calculateDistance(i, j, k);
                if(d < 0 || tmp < d || (tmp == d && (j < x || (j == x && k < y)))) {
                    x = j;
                    y = k;
                    d = tmp;
                }
            }
        }
    }

    cout << x << " " << y << " " << d << endl;
}

int32_t main() {
    go();
    mcsolve
    return 0;
}
