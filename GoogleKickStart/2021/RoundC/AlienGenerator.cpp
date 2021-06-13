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
#define mcsolve int T;cin >> T;for(int tt = 1;tt <= T;tt++) {cout << "Case #" << tt << ": ";solve();}
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
    ll n;cin >> n;
    ll ans = 1;
    for(ll i = 1;(i * (i + 1)) < (2 * n);i++) {
        double x = (1.0 * n - 1.0 * ((i * (i + 1)) / 2)) / (1.0 * (i + 1));
        if(x == floor(x)) {
            ans++;
        }
    }

    pf(ans);
}

int main() {
    go();
    mcsolve
    return 0;
}