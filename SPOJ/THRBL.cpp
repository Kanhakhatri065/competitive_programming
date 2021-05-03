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

//MAXN can be upto 1e7
const int MAXN = 1e5 + 5;
const int K = 25;

int log_of_2[MAXN + 1];
int st[MAXN][K + 1];

int n;
void precomputation(vector<int> arr) {
    log_of_2[1] = 0;
    for(int i = 2;i <= MAXN;i++) log_of_2[i] = log_of_2[i / 2] + 1;

    for(int i = 0;i < n;i++) st[i][0] = arr[i];

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = max(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
}

int query(int L, int R) {
    int j = log_of_2[R - L + 1];
    return max(st[L][j], st[R - (1 << j) + 1][j]);
}

void solve() {
    int m;
    cin >> n >> m;

    vector<int> arr(n);
    forIn(arr, n);

    precomputation(arr);
    
    int cnt = 0;
    while(m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int mx = query(min(a, b), max(a, b) - 1);
        if(mx == arr[a]) cnt++;
    }

    pf(cnt);
}

int main() {
    go();
    ssolve
    return 0;
}
