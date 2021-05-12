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
const int N = 1e5 + 5;
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

int par[N];
int rnk[N];
int num_comp;

void make_set(int v) {
    par[v] = v;
    rnk[v] = 0;
}

int find_set(int v) {
    return par[v] == v ? v : par[v] = find_set(par[v]);
}

void union_sets(int a, int b) {
    a = find_set(a), b = find_set(b);
    if(a != b) {
        num_comp--;
        if(rnk[a] < rnk[b]) swap(a, b);
        par[b] = a;
        if(rnk[a] == rnk[b]) rnk[a]++;
    }
}


void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    for(int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges.pb({u, v});
    }
  
    vector<int> queries, cnt(m + 1);
    int q;cin >> q;
    for(int i = 0;i < q;i++) {
        int x;cin >> x;x--;
        queries.pb(x);
        cnt[x]++;
    }

    for(int i = 0;i < n;i++) make_set(i);
    num_comp = n;
    for(int i = 0;i < m;i++) {
        if(cnt[i] > 0) continue;
        union_sets(edges[i].ff, edges[i].ss);
    }

    vector<int> ans;
    for(int i = q - 1;i >= 0;i--) {
        ans.pb(num_comp);
        union_sets(edges[queries[i]].ff, edges[queries[i]].ss);
    }
    
    reverse(all(ans));
    for(int x : ans) cout << x << " ";
    cout << endl;
}

int main() {
    go();
    int t;t = 1;
    while(t--) solve();
    return 0;
}
