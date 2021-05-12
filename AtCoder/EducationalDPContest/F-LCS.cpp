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

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    string a, b;
    cin >> a >> b;
    int n = sz(a), m = sz(b);

    vector<vector<pair<int, pair<int, int>>>> dp(n + 1, 
            vector<pair<int, pair<int, int>>>(m + 1, {-INF, {0, 0}})); 

    dp[0][0] = {0, {0, 0}};
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(a[i] == b[j]) {
                ckmax(dp[i + 1][j + 1], {dp[i][j].ff + 1, {i, j}});
            }
            ckmax(dp[i + 1][j], {dp[i][j].ff, {i, j}});
            ckmax(dp[i][j + 1], {dp[i][j].ff, {i, j}});
        }
    }

    pair<int, pair<int, int>> ans = {0, {0, 0}};
    for(int i = 0;i <= n;i++) {
        for(int j = 0;j <= m;j++) {
            ckmax(ans, {dp[i][j].ff, {i, j}});
        }
    }

    string s;
    pair<int, int> cur = ans.ss;
    while(!(cur.ff == 0 || cur.ss == 0)) {
        int i = cur.ff, j = cur.ss;
        pair<int, int> prev = dp[i][j].ss;
        if(prev == make_pair(i - 1, j - 1)) {
            s += a[i - 1];
        }

        cur = prev;
    }

    reverse(all(s));
    pf(s);
}

int main() {
    go();
    int t;t = 1;
    while(t--) solve();
    return 0;
}
