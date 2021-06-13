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

void solve() {
    int n;cin >> n;
    vector<int> v(n);
    for(int i = 0;i < n;i++) cin >> v[i];

    int mn = min_element(all(v)) - v.begin();
    int mx = max_element(all(v)) - v.begin();

    if(mn > mx) swap(mn, mx);
    int ans = max(mn + 1, mx + 1);
    ckmin(ans, mn + 1 + n - mx);
    ckmin(ans, mx + 1 + n - mn);
    ckmin(ans, max(n - mn, n - mx));
    pf(ans);
}

int main() {
    go();
    int t;cin >> t;
    while(t--) solve();
    return 0;
}