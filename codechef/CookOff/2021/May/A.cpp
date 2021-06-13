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
const int N = 1001;
ll a[N][N];
void precomputation() {
    for(int i = 1;i <= 1000;i++) {
        a[i][1] = i * (i + 1) / 2;
        for(int j = 2;j <= 1000;j++) {
            a[i][j] = a[i][j - 1] + (j - 1) + (i - 1);
        }
    }
}

void solve() {
    int x1, y1, x2, y2;cin >> x1 >> y1 >> x2 >> y2;

    ll sum = 0;
    for(int i = x1;i <= x2;i++) sum += a[i][y1];
    for(int i = y1 + 1;i <= y2;i++) sum += a[x2][i];
    pf(sum);
}

int main() {
    go();
    precomputation();
    int t;cin >> t;
    while(t--) solve();
    return 0;
}