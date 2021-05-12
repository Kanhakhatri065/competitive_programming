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
const int N = 305;

double dp[N][N][N];

double solve(int one, int two, int three, int &n) {
    if(one < 0 || two < 0 || three < 0) return 0;
    if(three == 0 && two == 0 && one == 0) return 0;
    if(dp[one][two][three]) return dp[one][two][three];

    int remaining = one + two + three;

    double expectedVal = n + one * solve(one - 1, two, three, n);
    expectedVal += two * solve(one + 1, two - 1, three, n);
    expectedVal += three * solve(one, two + 1, three - 1, n);

    dp[one][two][three] = expectedVal / (1.0 * remaining);
    return dp[one][two][three];
}

void solve() {
    int n;
    cin >> n;

    vector<int> cnt(4);
    for(int i = 0;i < n;i++) {
        int x;cin >> x;
        cnt[x]++;
    }

    memset(dp, 0, sizeof(dp));

    double ans = solve(cnt[1], cnt[2], cnt[3], n);
    cout << fixed << setprecision(10) << ans << endl;
}

int main() {
    go();
    int t = 1;
    while(t--) solve();
    return 0;
}