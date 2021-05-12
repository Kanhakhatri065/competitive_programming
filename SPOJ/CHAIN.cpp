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

int par[N], d[N];

int find_set(int v) {
    if(v == par[v]) return v;
    int tmp = par[v];
    par[v] = find_set(par[v]);
    d[v] += d[tmp];
    return par[v];
}

void solve() {
    int n, k;
    cin >> n >> k;

    for(int i = 1;i <= n;i++) {
        par[i] = i;
        d[i] = 0;
    }    

    int ans = 0;
    while(k--) {
        int t, x, y;cin >> t >> x >> y;
        if(x > n || y > n) {
            ans++;
            continue;
        }

        int px = find_set(x);
        int py = find_set(y);

        t--;
        if(px == py) {
            int tmp = (d[x] - d[y]) % 3;
            if(tmp < 0) tmp += 3;
            if(tmp != t) ans++;
        } else {
            par[px] = py;
            int tmp = (d[x] - d[y] - t) % 3;
            d[px] = tmp < 0 ? -tmp : -tmp + 3;
        }
    }

    pf(ans);
}

int main() {
    go();
    int t;cin >> t;
    while(t--) solve();
    return 0;
}
