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
    int n, t;
    cin >> n >> t;

    int k;cin >> k;

    int l = 1, r = n;
    cout << "? " << l << " " << r << endl;
    int zeros;
    cin >> zeros;
    while(l < r) {
        int m = (l + r) >> 1;
        cout << "? " << l << " " << m << endl;
        cin >> zeros;
        ll num_zeros = (m - l + 1) - zeros;
        if(num_zeros >= k) {
            r = m;
        } else {
            l = m + 1;
            k -= num_zeros;
        }
    }

    cout << "! " << l << endl;
}

int main() {
    //go();
    int t;t = 1;
    while(t--) solve();
    return 0;
}