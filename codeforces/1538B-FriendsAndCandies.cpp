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
    vector<ll> a(n);for(int i = 0;i < n;i++) cin >> a[i];

    ll sum = accumulate(all(a), 0LL);

    if(n == 1) {
        pf(0);
        return;
    }

    if(sum % n) {
        pf(-1);
        return;
    }

    sort(all(a));

    ll x = sum / n;

    if(a.back() == a.front()) {
        pf(0);
        return;
    }

    int ans = 1;

    int l = 0, r = n - 1;
    while(l < r) {
        if(a[l] == x) {
            l++;
            continue;
        }

        if(a[r] == x) {
            r--;
            ans++;
            continue;
        }

        a[l]++;
        a[r]--;
    }

    pf(ans);
}

int main() {
    go();
    int t;cin >> t;
    while(t--) solve();
    return 0;
}