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
const int N = 1024 + 5;

ll bit[N][N];
int n;
void add(int x, int y, ll num) {
    for(int i = x;i < n;i = i | (i + 1)) {
        for(int j = y;j < n;j = j | (j + 1)) {
            bit[i][j] += num;
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

void solve() {
    cin >> n;
    memset(bit, 0, sizeof(bit));

    string type;
    while(true) {
        cin >> type;
        if(type == "END") break;

        if(type == "SET") {
            int x, y;ll num;
            cin >> x >> y >> num;
            add(x, y, num);
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            ll ans = query(x2, y2);
            if(x1 - 1 >= 0) ans -= query(x1 - 1,  y2);
            if(y1 - 1 >= 0) ans -= query(x2, y1 - 1);
            if(x1 - 1 >= 0 && y1 - 1 >= 0) ans += query(x1 - 1, y1 - 1);
            pf(ans);
        }
    }
}

int main() {
    go();
    int t;cin >> t;
    while(t--) solve();
    return 0;
}