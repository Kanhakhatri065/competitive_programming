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
const int N = 1e5 + 5;


void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<array<int, 2>> cnt(n + 1);
    for(int i = 0;i < l;i++) {
        int x;cin >> x;
        cnt[x][0]++;
    }

    for(int i = 0;i < r;i++) {
        int x;cin >> x;
        cnt[x][1]++;
    }
    
    int ans = 0;
    int left = 0, right = 0;
    for(int i = 1;i <= n;i++) {
        int mn = min(cnt[i][0], cnt[i][1]);
        cnt[i][0] -= mn;
        cnt[i][1] -= mn;

        if(cnt[i][0] > 0) {
            left += cnt[i][0];
        } else {
            right += cnt[i][1];
        }
    }

    for(int i = 1;i <= n;i++) {
        if(cnt[i][0] > 0) {
            while(left > right) {
                if(cnt[i][0] <= 1) break;
                left -= 2;
                cnt[i][0] -= 2;
                ans++;
            }
        } else {
            while(right > left) {
                if(cnt[i][1] <= 1) break;
                right -= 2;
                cnt[i][1] -= 2;
                ans++;
            }
        }
    }

    //cout << "P1 ans : " << ans << endl;
    while(left != right) {
        ans++;
        if(left > right) {
            left--, right++;
        } else {
            right--, left++;
        }
    }
    //cout << "P2 ans : " << ans << endl;
    ans += left;
    pf(ans);
}

int main() {
    go();
    msolve
    return 0;
}
