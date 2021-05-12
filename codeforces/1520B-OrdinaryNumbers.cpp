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
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
vector<ll> store;
void precomputation() {
    for(int i = 1;i <= 10;i++) {
        for(int j = 1;j < 10;j++) {
            string tmp(i, j + '0');
            ll num = stoll(tmp);
            store.pb(num);
        }
    }
}

void solve() {
    int n;
    cin >> n;

    auto it = lower_bound(all(store), n);
    
    if(*it == n) {
        int ans = it - store.begin();
        ans++;
        pf(ans);
    } else {
        int ans = it - store.begin();
        pf(ans);
    }
}

int main() {
    go();
    precomputation();
    //for(ll x : store) pf(x);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}