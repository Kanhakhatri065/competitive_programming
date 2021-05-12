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
}
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n + 1);
    for(int i = 1;i <= n;i++) cin >> a[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    for(int i = n;i >= 0;i--) {
        for(int j = i;j <= n;j++) {
            if(i == j) {
                dp[i][j] = a[i];
            } else {
                dp[i][j] = max((a[i] - dp[i + 1][j]), (a[j] - dp[i][j - 1]));
            }
        }
    }

    pf(dp[1][n]);
}

int main() {
    go();
    int t = 1;
    while(t--) solve();
    return 0;
}