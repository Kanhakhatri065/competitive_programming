#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pf(a) cout << a << endl
#define forIn(arr, num) for(int i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(auto it : ans) {cout << it << " ";}cout << endl;
#define sz(x) (int)(x).size()
#define pb push_back
#define mem(a, b) memset(a,(b), sizeof(a))
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
void go() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
}
#define ssolve solve();
#define msolve int T;cin >> T;while(T--) {solve();}
#define mcsolve int T;cin >> T;for(int tt = 1;tt <= T;tt++) {cout << "Case #" << tt << ": ";solve();}
string to_string(string s) {
  return '"' + s + '"';
}
string to_string(const char* s) {
  return to_string((string) s);
}
string to_string(bool b) {
  return (b ? "true" : "false");
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int N = 3010;

ll dp[N][N][4];
ll v[N][N];

void solve() {
    int n, m, p;
    cin >> n >> m >> p;
    mem(v, 0);
    for(int i = 0;i < p;i++) {
        int x, y, val;
        cin >> x >> y >> val;
        x--, y--;
        v[x][y] = val;
    }

    for(int i = 0;i < N;i++) for(int j = 0;j < N;j++) for(int k = 0;k < 4;k++) dp[i][j][k] = LLONG_MIN;
    
    dp[0][0][0] = 0;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            for(int k = 2;k >= 0;k--) {
                ckmax(dp[i][j][k + 1], dp[i][j][k] + v[i][j]);
            }

            for(int k = 0;k < 4;k++) {
                if(dp[i][j][k] >= 0) {
                    if(i + 1 < n) {
                        ckmax(dp[i + 1][j][0], dp[i][j][k]);
                    }

                    if(j + 1 < m) {
                        ckmax(dp[i][j + 1][k], dp[i][j][k]);
                    }
                }
            }
        }
    }

    ll ans = LLONG_MIN;
    for(int k = 0;k < 4;k++) ckmax(ans, dp[n - 1][m - 1][k]);
    pf(ans);
}

int main() {
    go();
    ssolve
    return 0;
}
