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

ll MOD;
const int N = 400 + 5;

int n;
ll dp[N][N];

ll fastexp(ll b, ll exp) {
    if(exp == 0) return 1;

    ll tmp = fastexp(b, exp / 2);
    tmp = (tmp * tmp) % MOD;
    if(exp & 1) tmp *= b;
    return tmp % MOD;
}

ll fact[N], inv[N], choose[N][N], pow2[N];
void precomputation() {
    fact[0] = 1;
    inv[0] = 1;

    for(int i = 1;i <= n;i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv[i] = fastexp(fact[i], MOD - 2);
    }

    for(int i = 0;i <= n;i++) {
        for(int j = 0;j <= i;j++) {
            choose[i][j] = ((fact[i] * inv[j]) % MOD * inv[i - j]) % MOD;
        }
    }

    for(int i = 0;i <= n;i++) {
        pow2[i] = fastexp(2, i);
    }
}

void solve() {
    cin >> n >> MOD;
    precomputation();
    dp[0][0] = 1;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j <= i;j++) {
            for(int k = 1;i + k <= n;k++) {
                dp[i + k + 1][j + k] += ((dp[i][j] * pow2[k - 1]) % MOD * choose[j + k][k]);
                dp[i + k + 1][j + k] %= MOD;
            }
        }
    }

    ll ans = 0;
    for(int i = 0;i <= n;i++) {
        ans += dp[n + 1][i];
        ans %= MOD;
    }

    pf(ans);
}

int main() {
    go();
    ssolve
    return 0;
}
