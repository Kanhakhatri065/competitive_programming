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
#ifdef LOCAL
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
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
const int N = 2e5 + 5;

int n, k, a;
int spc[N];
vector<int> adj[N];
int has[N];
int dep[N], closest[N], spnode[N];

void prep(int x, int par) {
    has[x] |= spc[x];

    int spn = 0;
    for(int y : adj[x]) {
        if(y == par) continue;
        dep[y] = dep[x] + 1;
        prep(y, x);
        has[x] |= has[y];
        if(has[y]) spn = spnode[y];
    }

    if(spc[x]) spnode[x] = x;
    else spnode[x] = spn;
}

void dfs(int x, int par) {
    if(has[x]) closest[x] = x;
    else closest[x] = closest[par];

    for(int y : adj[x]) {
        if(y == par) continue;
        dfs(y, x);
    }
}

void solve() {
    cin >> n >> k >> a;
    for(int i = 1;i <= n;i++) {
        adj[i].clear();
        spc[i] = dep[i] = closest[i] = has[i] = spnode[i] = 0;
    }

    for(int i = 1;i <= k;i++) {
        int x;cin >> x;
        spc[x] = 1;
    }

    for(int i = 1;i < n;i++) {
        int u, v;cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dep[a] = 0;
    prep(a, 0);
    dfs(a, 0);

    for(int i = 1;i <= n;i++) {
        int mx = 2 * dep[closest[i]] - dep[i];
        cout << mx << " ";
    }
    cout << endl;

    for(int i = 1;i <= n;i++) {
        cout << spnode[closest[i]] << " ";
    }
    cout << endl;
}

int main() {
    go();
    msolve
    return 0;
}