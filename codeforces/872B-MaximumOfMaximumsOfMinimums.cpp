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
const int N = 1e5 + 5;


void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    forIn(v, n);

    map<int, vector<int>> mp;
    for(int i = 0;i < n;i++) {
        mp[v[i]].pb(i);
    }

    if(k == 1) {
        pf(mp.begin()->ff);
    } else if(k == 2) {
        if(mp.rbegin()->ss.front() == 0) {
            pf(mp.rbegin()->ff);
        } else if(mp.rbegin()->ss.back() == n - 1) {
            pf(mp.rbegin()->ff);
        } else {
            vector<int> pre_mn(n);
            pre_mn[0] = v[0];
            for(int i = 1;i < n;i++) {
                pre_mn[i] = min(pre_mn[i - 1], v[i]);
            }

            vector<int> suf_mn(n);
            suf_mn[n - 1] = v[n - 1];
            for(int i = n - 2;i >= 0;i--) suf_mn[i] = min(suf_mn[i + 1], v[i]);

            int mx = INT_MIN;
            for(int i = 0;i + 1 < n;i++) {
                ckmax(mx, max(pre_mn[i], suf_mn[i + 1]));
            }

            pf(mx);
        }
    } else {
        pf(mp.rbegin()->ff);
    }
}

int main() {
    go();
    ssolve
    return 0;
}
