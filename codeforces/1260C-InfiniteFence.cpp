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
    ll a, b, k;
    cin >> a >> b >> k;

    ll g = __gcd(a, b);
    a /= g;
    b /= g;

    if(a > b) swap(a, b);

    if((k - 1) * a + 1 < b) {
        pf("REBEL");
    } else {
        pf("OBEY");
    }
} 

int main() {
    go();
    int t;cin >> t;
    while(t--) solve();
    return 0;
}