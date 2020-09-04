/*** I came, I saw, I conquered. ***/
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;typedef unsigned long long ull;
/*** Input Output ***/
#define sc(a) cin >> a
#define pf(a) cout << a << endl
/*** Loops ***/
#define f(i, p, num) for(ll i = p; i < num; i++)
#define forIn(arr, num) for(ll i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
/*** Define Values ***/
#define mod1 1000000007
#define mod2 998244353
#define eps 1e-7
/*** Abbrevations **/
#define pb push_back
#define ff first
#define ss second
#define mem(name, value) memset(name, value, sizeof(name))
/*** STLs ***/
typedef vector<ll>vll;typedef set<ll>sll;typedef multiset<ll>msll;
typedef map<ll,ll>mll;typedef pair<ll,ll>pll;
/*** Sorts ***/
#define all(v) (v).begin(), (v).end()
#define srt(v) sort(all(v))
/*** Bit-Stuff ***/
#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
/*** Some Prints ***/
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
/*----------------------------------------------------------------*/
const int LMT = 605;
int t[4 * LMT][4 * LMT];
int p[4 * LMT][4 * LMT];
int a[LMT][LMT];
int m, n;
void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
    if(ly == ry) {
        if(lx == rx) {
            t[vx][vy] = a[lx][ly];
            p[vx][vy] = a[lx][ly];
        } else {
            t[vx][vy] = max(t[vx * 2][vy], t[vx * 2 + 1][vy]);
            p[vx][vy] = min(p[vx * 2][vy], p[vx * 2 + 1][vy]);
        }
    } else {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy * 2, ly, my);
        build_y(vx, lx, rx, vy * 2 + 1, my + 1, ry);
        t[vx][vy] = max(t[vx][vy * 2], t[vx][vy * 2 + 1]);
        p[vx][vy] = min(p[vx][vy * 2], p[vx][vy * 2 + 1]);
    }
}

void build_x(int vx, int lx, int rx) {
    if(lx != rx) {
        int mx = (lx + rx) / 2;
        build_x(vx * 2, lx, mx);
        build_x(vx * 2 + 1, mx + 1, rx);
    }

    build_y(vx, lx, rx, 1, 0, m - 1);
}

void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
    if(ly == ry) {
        if(lx == rx) {
            t[vx][vy] = new_val;
            p[vx][vy] = new_val;
        } else {
            t[vx][vy] = max(t[vx * 2][vy], t[vx * 2 + 1][vy]);
            p[vx][vy] = min(p[vx * 2][vy], p[vx * 2 + 1][vy]);
        }
    } else {
        int my = (ly + ry) / 2;
        if(y <= my) {
            update_y(vx, lx, rx, vy * 2, ly, my, x, y, new_val);
        } else {
            update_y(vx, lx, rx, vy * 2 + 1, my + 1, ry, x, y, new_val);
        }

        t[vx][vy] = max(t[vx][vy * 2], t[vx][vy * 2 + 1]);
        p[vx][vy] = min(p[vx][vy * 2], p[vx][vy * 2 + 1]);
    }
}

void update_x(int vx, int lx, int rx, int x, int y, int new_val) {
    if(lx != rx) {
        int mx = (lx + rx) / 2;
        if(x <= mx) {
            update_x(vx * 2, lx, mx, x, y, new_val);
        } else {
            update_x(vx * 2 + 1, mx + 1, rx, x, y, new_val);
        }
    }
    update_y(vx, lx, rx, 1, 0, m - 1, x, y, new_val);
}

pair<int, int> query_y(int vx, int vy, int tly, int try_, int ly, int ry) {
    if(ly > ry) {
        return pair<int, int>(-1, 1 << 30); 
    }

    if(ly == tly && try_ == ry) {
        return pair<int, int>(t[vx][vy], p[vx][vy]);
    }

    int tmy = (tly + try_) / 2;
    pair<int, int> r1 = query_y(vx, vy * 2, tly, tmy, ly, min(ry, tmy));
    pair<int, int> r2 = query_y(vx, vy * 2 + 1, tmy + 1, try_, max(ly, (tmy + 1)), ry);

    return pair<int, int>(max(r1.ff, r2.ff), min(r1.ss, r2.ss));
}

pair<int, int> query_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if(lx > rx) {
        return pair<int, int>(-1, 1 << 30);
    }

    if(lx == tlx && rx == trx) {
        return query_y(vx, 1, 0, m - 1, ly, ry);
    }

    int tmx = (tlx + trx) / 2;

    pair<int, int> r1 = query_x(vx * 2, tlx, tmx, lx, min(rx, tmx), ly, ry);
    pair<int, int> r2 = query_x(vx * 2 + 1, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry);

    return pair<int, int>(max(r1.ff, r2.ff), min(r1.ss, r2.ss));
}

int val;

void solve() {
    cin >> n;
    m = n;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin >> a[i][j];
        }
    }

    int q;
    cin >> q;
    char ch;
    int x1, x2, y1, y2;
    while(q--) {
        cin >> ch;
        if(ch == 'q') {
            cin >> x1 >> y1 >> x2 >> y2;
            x1--, y1--, x2--, y2--;

            pair<int, int> ans = query_x(1, 0, n - 1, x1, x2, y1, y2);
            cout << ans.ff << " " << ans.ss << endl;
        } else {
            cin >> x1 >> y1 >> val;
            x1--;
            y1--;

            update_x(1, 0, n - 1, x1, y1, val);
        }
    }
}

int main() {
    FAST_IO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();
    return 0;
}