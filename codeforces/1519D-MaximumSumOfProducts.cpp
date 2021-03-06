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

const int MOD = 1e9 + 7;
const int N = 5005;

void solve() {
    int n;cin >> n;
    
    vector<ll> a(n);
    forIn(a, n);
    vector<ll> b(n);
    forIn(b, n); 
    
    ll total = 0, ans = 0;
    for(int i = 0;i < n;i++) total += a[i] * b[i];
    ckmax(ans, total);

    for(int center = 0;center < n;center++) {
        ll cur = total;
        for(int x = center - 1, y = center + 1;x >= 0 && y < n;x--, y++) {
            cur -=  a[x] * b[x] + a[y] * b[y];
            cur += a[x] * b[y] + a[y] * b[x];
            ckmax(ans, cur);
        }
    }

    for(int between = 0;between + 1 < n;between++) {
        ll cur = total;
        for(int x = between, y = between + 1;x >= 0 && y < n;x--, y++) {
            cur -= a[x] * b[x] + a[y] * b[y];
            cur += a[x] * b[y] + a[y] * b[x];
            ckmax(ans, cur);
        }
    }

    pf(ans);
}

int main() {
    go();
    ssolve
    return 0;
}
