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
const int N = 2e5 + 5;
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

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    
    for(int i = 1;i <= n;i++) cin >> a[i] >> b[i];

    set<pair<int, int>> ans_store;
    map<int, set<pair<int, int>>> store;
 
    for(int i = 1;i <= n;i++) {
        store[b[i]].insert({a[i], i});
    }

    for(auto it : store) {
        ans_store.insert(*it.ss.rbegin());
    }

    while(q--) {
        int c, d;cin >> c >> d;
        int cur = b[c];
        
        ans_store.erase(*store[cur].rbegin());
        store[cur].erase({a[c], c});
        if(!store[cur].empty()) {
            ans_store.insert(*store[cur].rbegin());
        }

        b[c] = d;
        cur = d;
        if(!store[cur].empty()) ans_store.erase(*store[cur].rbegin());
        store[cur].insert({a[c], c});
        ans_store.insert(*store[cur].rbegin());
        //cout << "Ans : ";
        pf(ans_store.begin()->ff);
    }
}

int main() {
    go();
    int t;t = 1;
    while(t--) solve();
    return 0;
}
