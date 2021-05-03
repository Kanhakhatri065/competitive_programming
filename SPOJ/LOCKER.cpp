#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
ll binpow(ll a, ll n) {
    ll res = 1;
    a %= MOD;
    while(n) {
        if(n & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return res;
}
void solve() {
    ll n;cin >> n;
    if(n < 3) {
        cout << n << endl;
        return;
    }
    ll ans, tmp;
    if(n % 3 == 1) {
        tmp = (n - 4) / 3;
        ans = 4 * binpow(3, tmp);
    } else if(n % 3 == 2) {
        tmp = (n - 2) / 3;
        ans = 2 * binpow(3, tmp);
    } else {
        tmp = n / 3;
        ans = binpow(3, tmp);
    }
    ans %= MOD;
    cout << ans << endl;
}
int main() {
    int t;cin >> t;
    while(t--) solve();
    return 0;
}
