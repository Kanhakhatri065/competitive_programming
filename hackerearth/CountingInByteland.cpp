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
const int N = 102;
ll bit[N][N][N];
int n;
void add(int x, int y, int z, ll val) {
    for(int i = x;i <= n;i += (i & (-i))) {
        for(int j = y;j <= n;j += (j & (-j))) {
            for(int k = z;k <= n;k += (k & (-k))) {
                bit[i][j][k] += val;
            }
        }   
    }
}

ll query(int x, int y, int z) {
    ll res = 0;
    for(int i = x;i > 0;i -= (i & (-i))) {
        for(int j = y;j > 0;j -= (j & (-j))) {
            for(int k = z;k > 0;k -= (k & (-k))) {
                res += bit[i][j][k];
            }
        }
    }

    return res;
}

ll query(int x, int y, int z, int X, int Y, int Z) {
    ll ans = query(X, Y, Z);
    ans -= query(x, Y, Z);
    ans -= query(X, y, Z);
    ans -= query(X, Y, z);
    ans += query(x, y, Z);
    ans += query(x, Y, z);
    ans += query(X, y, z);
    ans -= query(x, y, z);
    return ans;
}

void solve() {
    int q;
    cin >> n >> q;
    n++;
    ll total = 0;
    while(q--) {
        int type;cin >> type;
        if(type == 1) {
            int x, y, z;ll val;
            cin >> x >> y >> z >> val;
            total += val;
            add(x + 1, y + 1, z + 1, val);
        } else {
            int x1, y1, z1, x2, y2, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            ll ans = query(x1, y1, z1, x2 + 1, y2 + 1, z2 + 1);
            ans = total - ans;
            pf(ans);
        }
    }
}

int main() {
    go();
    int t;t = 1;
    while(t--) solve();
    return 0;
}
