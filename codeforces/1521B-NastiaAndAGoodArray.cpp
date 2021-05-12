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
#ifdef LOCAL
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
}
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
int a[N];
void solve() {
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    vector<pi> store;
    for(int i = 1;i <= n;i++) {
        store.pb({a[i], i});
    }

    sort(all(store));

    vector<pair<pi, pi>> ans;
    if(store[0].ss != 1) {
        ans.pb({{1, store[0].ss}, {store[0].ff, store[0].ff + store[0].ss - 1}});
        a[1] = store[0].ff;
        a[store[0].ss] = store[0].ff + store[0].ss - 1;
    }

    for(int i = 1;i < sz(store);i++) {
        if(store[i].ss == 1) continue;
        ans.pb({{1, store[i].ss}, {a[1], a[1] + store[i].ss - 1}});
        a[store[i].ss] = a[1] + store[i].ss - 1;
    }

    // for(int i = 1;i <= n;i++) cout << a[i] << " ";
    // cout << endl;

    pf(sz(ans));
    for(auto it : ans) cout << it.ff.ff << " " << it.ff.ss << " " << it.ss.ff << " " << it.ss.ss << endl;
}

int main() {
    go();
    int t;cin >> t;
    while(t--) solve();
    return 0;
}