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
    int a, b;cin >> a >> b;
    ll k;cin >> k;

    vector<vector<ll>> dp(a + 1, vector<ll>(b + 1));
    
    dp[0][0] = 1;
    for(int i = 0;i <= a;i++) {
        for(int j = 0;j <= b;j++) {
            if(i > 0) dp[i][j] += dp[i - 1][j];
            if(j > 0) dp[i][j] += dp[i][j - 1];
        }
    }

    string ans = "";
    while(a > 0 && b > 0) {
        if(k <= dp[a - 1][b]) {
            ans += 'a';
            a--;
        } else {
            k -= dp[a - 1][b];
            ans += 'b';
            b--;
        }
    }

    ans += string(a, 'a');
    ans += string(b, 'b');
    pf(ans);
}

int main() {
    go();
    int t = 1;
    while(t--) solve();
    return 0;
}