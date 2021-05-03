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
struct Mint {
    int val;
 
    Mint(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
        if (v >= MOD)
            v %= MOD;
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        } 
        return x < 0 ? x + m : x;
    } 
    explicit operator int() const {
        return val;
    }
    Mint& operator+=(const Mint &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    Mint& operator-=(const Mint &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x;
           unsigned quot, rem;
           asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
    Mint& operator*=(const Mint &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
    Mint& operator/=(const Mint &other) {
        return *this *= other.inv();
    }
    friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
    friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
    friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
    friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
    Mint& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
    Mint& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
    Mint operator++(int32_t) { Mint before = *this; ++*this; return before; }
    Mint operator--(int32_t) { Mint before = *this; --*this; return before; }
    Mint operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
    bool operator==(const Mint &other) const { return val == other.val; }
    bool operator!=(const Mint &other) const { return val != other.val; }
    Mint inv() const {
        return mod_inv(val);
    }
    Mint power(long long p) const {
        assert(p >= 0);
        Mint a = *this, result = 1;
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
        return result;
    }
    friend ostream& operator << (ostream &stream, const Mint &m) {
        return stream << m.val;
    }
    friend istream& operator >> (istream &stream, Mint &m) {
        return stream>>m.val;   
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    forIn(v, n);

    Mint ans = 0;
    for(int i = 0;i < n;i++) ans += v[i];

    int q;
    cin >> q;
    while(q--) {
        int x;cin >> x;
        ans *= 2;
        pf(ans);
    }
}

int main() {
    go();
    ssolve
    return 0;
}
