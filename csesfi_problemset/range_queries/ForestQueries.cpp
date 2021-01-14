/*
	I love the sound you make when you shut up.
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
/*----typedefs--------*/
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
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
const int N = 1000 + 5;
/*-------------- Push your limits here ---------------------------*/
int a[N][N], t[4 * N][4 * N];
int n, q;
void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
    if(ly == ry) {
        if(lx == rx) {
            t[vx][vy] = a[lx][ly];
        } else {
            t[vx][vy] = t[vx << 1][vy] + t[vx << 1 | 1][vy];
        }
    } else {
        int my = (ly + ry) >> 1;
        build_y(vx, lx, rx, vy << 1, ly, my);
        build_y(vx, lx, rx, vy << 1 | 1, my + 1, ry);
        t[vx][vy] = t[vx][vy << 1] + t[vx][vy << 1 | 1];
    }
}

void build_x(int vx, int lx, int rx) {
    if(lx != rx) {
        int mx = (lx + rx) >> 1;
        build_x(vx << 1, lx, mx);
        build_x(vx << 1 | 1, mx + 1, rx);
    }
    build_y(vx, lx, rx, 1, 0, n - 1);
}

int sum_y(int vx, int vy, int tly, int try_, int ly, int ry) {
    if(ly > ry) {
        return 0;
    }

    if(ly == tly && ry == try_) {
        return t[vx][vy];
    } 

    int tmy = (tly + try_) >> 1;
    return sum_y(vx, vy << 1, tly, tmy, ly, min(ry, tmy)) + sum_y(vx, vy << 1 | 1, tmy + 1, try_, max(ly, tmy + 1), ry);
}

int sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if(lx > rx) return 0;

    if(lx == tlx && rx == trx) {
        return sum_y(vx, 1, 0, n - 1, ly, ry);
    }

    int tmx = (tlx + trx) >> 1;
    return sum_x(vx << 1, tlx, tmx, lx, min(rx, tmx), ly, ry) + sum_x(vx << 1 | 1, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry);
}

void solve() {
    cin >> n >> q;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            char c;cin >> c;
            if(c == '*') {
                a[i][j] = 1;
            } else {
                a[i][j] = 0;
            }
        }
    }
    
    build_x(1, 0, n - 1);
    while(q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;

        pf(sum_x(1, 0, n - 1, x1, x2, y1, y2));
    }
}

int main() {
    //go();
    ssolve
    return 0;
}

