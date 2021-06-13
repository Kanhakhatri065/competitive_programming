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

ll formalize(ll x) {
    return (1LL * x * (x + 1)) / 2;
}
void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];

    vector<ll> dp(n, 0);
    map<ll, ll> val;

    ll ans = 0;
    for(int i = 0;i < n;i++) {
        if(i > 0) dp[i] = dp[i - 1];
        if(val.count(a[i])) {
            dp[i] += val[a[i]];
        }

        val[a[i]] += (i + 1);
        ans += dp[i];
    }

    pf(ans);
}

int main() {
    go();
    int t;cin >> t;
    while(t--) solve();
    return 0;
}