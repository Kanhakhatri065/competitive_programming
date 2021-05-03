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

const int INF = 1e9 + 7;
const int N = 505;

int a[N][N], b[N][N];
ll dp[N][N];

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0;i < n;i++) for(int j = 0;j + 1 < m;j++) cin >> a[i][j];
    for(int i = 0;i + 1 < n;i++) for(int j = 0;j < m;j++) cin >> b[i][j];
    for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) dp[i][j] = 1e18;

    dp[0][0] = 0;
    priority_queue<pair<ll, pair<int, int>>> pq;
    pq.push({0, {0, 0}});
    while(!pq.empty()) {
        ll c = -pq.top().ff;
        int y = pq.top().ss.ff, x = pq.top().ss.ss;
        pq.pop();

        if(dp[x][y] < c) continue;

        if(y + 1 < m) {
            ll nxt = c + a[x][y];
            if(ckmin(dp[x][y + 1], nxt)) {
                pq.push({-nxt, {y + 1, x}});
            }
        }

        if(y - 1 >= 0) {
            ll nxt = c + a[x][y - 1];
            if(ckmin(dp[x][y - 1], nxt)) {
                pq.push({-nxt, {y - 1, x}});
            }
        }

        if(x + 1 < n) {
            ll nxt = c + b[x][y];
            if(ckmin(dp[x + 1][y], nxt)) {
                pq.push({-nxt, {y, x + 1}});
            }
        }

        for(int i = 1;i <= x;i++) {
            ll nxt = c + i + 1;
            if(ckmin(dp[x - i][y], nxt)) {
                pq.push({-nxt, {y, x - i}});
            }
        }
    }

    pf(dp[n - 1][m - 1]);
}

int main() {
    go();
    ssolve
    return 0;
}
