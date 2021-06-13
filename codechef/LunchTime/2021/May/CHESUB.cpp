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
const ll INF = 1e18;
const int N = 1e5 + 5;
const int K = 110;

ll dp[N][K];
ll prefix[N][K];

void solve() {
  int n, k;cin >> n >> k;
  
  vector<ll> a(n);for(int i = 0;i < n;i++) cin >> a[i];
  vector<ll> b(k);for(int i = 0;i < k;i++) b[i] = i + 1;

  for(int i = 0;i < n;i++) {
    dp[i][0] = 0;
    prefix[i][0] = 0;
    for(int j = 1;j <= k;j++) {
      dp[i][j] = -INF;
      prefix[i][j] = -INF;
    }
  }

  dp[0][1] = a[0] * b[0];
  prefix[0][1] = dp[0][1];

  for(int i = 1;i < n;i++) {
    for(int j = 1;j <= k;j++) {
      dp[i][j] = max(dp[i - 1][j], prefix[i - 1][j - 1]) + a[i] * b[j - 1];
      ckmax(dp[i][j], -INF);
      prefix[i][j] = max(prefix[i - 1][j], dp[i][j]);
    }
  }

  ll ans = -INF;
  for(int i = 0;i < n;i++) {
    ckmax(ans, dp[i][k]);
  }

  pf(ans);
}

int main() {
    go();
    int t;cin >> t;
    while(t--) solve();
    return 0;
}