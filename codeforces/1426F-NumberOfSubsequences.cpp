/*** I came, I saw, I conquered. ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef unsigned long long ull;
#define sc(a) cin >> a
#define pf(a) cout << a << endl
#define forIn(arr, num) for(ll i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
#define mod 1000000007
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
void go() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
/*----------------------------------------------------------------*/
const ll MOD = 1e9 + 7;
void solve() {
    int n;
    sc(n);

    string s;
    sc(s);

    vector<vector<ll>> dp(n + 1, vector<ll>(4, 0));
    dp[0][0] = 1;

    for(int i = 0;i < n;i++) {
        dp[i + 1] = dp[i];

        if(s[i] == 'a') {
            dp[i + 1][1] += dp[i][0];
            dp[i + 1][1] %= MOD;
        }

        if(s[i] == 'b') {
            dp[i + 1][2] += dp[i][1];
            dp[i + 1][2] %= MOD;
        }

        if(s[i] == 'c') {
            dp[i + 1][3] += dp[i][2];
            dp[i + 1][3] %= MOD;
        }

        if(s[i] == '?') {
            dp[i + 1][0] = dp[i][0] * 3;
            dp[i + 1][0] %= MOD;

            dp[i + 1][1] = dp[i][1] * 3 + dp[i][0];
            dp[i + 1][1] %= MOD;
            
            dp[i + 1][2] = dp[i][2] * 3 + dp[i][1];
            dp[i + 1][2] %= MOD;
            
            dp[i + 1][3] = dp[i][3] * 3 + dp[i][2];
            dp[i + 1][3] %= MOD;
        }
    }

    pf(dp[n][3]);
}   

int main() {
    go();
    solve();
    return 0;
}