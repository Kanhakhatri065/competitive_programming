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

    double prob[n + 1];
    for(int i = 1;i <= n;i++) cin >> prob[i];

    double dp[n + 1][n + 1];
    for(int i = 0;i <= n;i++) for(int j = 0;j <= n;j++) dp[i][j] = 0;

    dp[1][0] = 1.0 - prob[1];
    for(int i = 2;i <= n;i++) dp[i][0] = dp[i - 1][0] * (1.0 - prob[i]);

    dp[1][1] = prob[1];
    for(int i = 2;i <= n;i++) dp[i][i] = dp[i - 1][i - 1] * prob[i];

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j < i;j++) {
            dp[i][j] = dp[i - 1][j] * (1.0 - prob[i]) + dp[i - 1][j - 1] * prob[i];
        }
    }

    double res = 0;
    for(int i = n / 2 + 1;i <= n;i++) {
        res += dp[n][i];
    }

    cout << fixed << setprecision(10) << res << endl;
}

int main() {
    go();
    int t = 1;
    while(t--) solve();
    return 0;
}
