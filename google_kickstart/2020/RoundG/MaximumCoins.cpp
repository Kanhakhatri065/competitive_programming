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
#define int long long
const int N = 1e3 + 5;
int c[N][N];
int dp[N][N];
int n;
void solve() {
    cin >> n;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cin >> c[i][j];
        }
    }

    memset(dp, 0, sizeof(dp));
    for(int i = n - 1;i >= 0;i--) {
        for(int j = n - 1;j >= 0;j--) {
            dp[i][j] += c[i][j];
            dp[i][j] += dp[i + 1][j + 1];

            if(j > 0 && i > 0) {
                dp[i][j] += dp[i - 1][j - 1];
            }
        }
    }

    int ans = 0;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    pf(ans);
}

int32_t main() {
    go();
    int t;
    sc(t);

    for(int tt = 1;tt <= t;tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }

    return 0;
}