#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pf(a) cout << a << endl
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
void go() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
}
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

struct FenwickTree2D {
    int n, m;
    vector<vector<ll>> bit;

    FenwickTree2D(vector<vector<int>> a) {
        n = sz(a), m = sz(a[0]);
        bit.assign(n, vector<ll>(m));
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                add(i, j, a[i][j]);
            }
        }
    }

    void add(int x, int y, int val) {
        for(int i = x;i < n;i = i | (i + 1)) {
            for(int j = y;j < m;j = j | (j + 1)) {
                bit[i][j] += val;
            }
        }
    }

    ll query(int x, int y) {
        ll res = 0;
        for(int i = x;i >= 0;i = (i & (i + 1)) - 1) {
            for(int j = y;j >= 0;j = (j & (j + 1)) - 1) {
                res += bit[i][j];
            }
        }

        return res;
    }

    ll query(int x1, int y1, int x2, int y2) {
        ll ans = query(x2, y2);
        if(x1 - 1 >= 0) ans -= query(x1 - 1, y2);
        if(y1 - 1 >= 0) ans -= query(x2, y1 - 1);
        if(x1 - 1 >= 0 && y1 - 1 >= 0) ans += query(x1 - 1, y1 - 1);
        return ans;
    }
};

void solve() {
    int n, m, c;
    cin >> n >> m >> c;

    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) cin >> a[i][j];

    FenwickTree2D ft(a);

    while(c--) {
        int type;cin >> type;
        if(type == 1) {
            int x, y;ll p;
            cin >> x >> y >> p;
            x--, y--;

            ft.add(x, y, p);
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--, y1--, x2--, y2--;
            ll ans = ft.query(x1, y1, x2, y2);
            pf(ans);
        }
    }
}

int main() {
    go();
    int t = 1;
    while(t--) solve();
    return 0;
}