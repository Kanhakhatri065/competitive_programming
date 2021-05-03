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
const int K = 25;
int log_of_2[N + 1];
int max_st[N][K + 1];
int min_st[N][K + 1];
int n, q;
void precomputation(vector<int> arr) {
    log_of_2[1] = 0;
    for(int i = 2;i <= N;i++) log_of_2[i] = log_of_2[i / 2] + 1;

    for(int i = 0;i < n;i++) {
        max_st[i][0] = arr[i];
        min_st[i][0] = arr[i];
    }

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= N; i++)
            min_st[i][j] = min(min_st[i][j-1], min_st[i + (1 << (j - 1))][j - 1]); 

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= N; i++)
            max_st[i][j] = max(max_st[i][j-1], max_st[i + (1 << (j - 1))][j - 1]);
}

int min_query(int l, int r) {
    int j = log_of_2[r - l + 1];
    return min(min_st[l][j], min_st[r - (1 << j) + 1][j]);
}

int max_query(int l, int r) {
    int j = log_of_2[r - l + 1];
    return max(max_st[l][j], max_st[r - (1 << j) + 1][j]);
}

void solve() {
    cin >> n;
    vector<int> v(n);
    forIn(v, n);
    precomputation(v);
    cin >> q;

    while(q--) {
        int l, r;
        cin >> l >> r;

        int mn_in = min_query(l, r), mx_in = max_query(l, r);
        int mx_out = max((l - 1) >= 0 ? max_query(0, l - 1) : 0, (r + 1) < n ? max_query(r + 1, n - 1) : 0);

        double ans = max(1.0 * mx_out + mn_in, 1.0 * mn_in + (1.0 * (mx_in - mn_in) / 2));
        cout << fixed << setprecision(1) << ans << endl;
    }
}

int main() {
    go();
    ssolve
    return 0;
}
