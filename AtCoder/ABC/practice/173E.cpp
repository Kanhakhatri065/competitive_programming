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
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    vector<ll> p, m;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        if(a[i] >= 0) p.pb(a[i]);
        else m.pb(a[i]);
    }

    if(n == k) {
        Mint res = 1;
        for(int i = 0;i < n;i++) {
            res *= (Mint)a[i];
        }

        pf(res);
        return;
    }

    if(sz(p) == 0 && k & 1) {
        sort(all(m), greater<>());
        Mint res = 1;
        for(int i = 0;i < k;i++) {
            res *= (Mint)m[i];
        }

        pf(res);
        return;
    }

    sort(all(p), greater<>());
    sort(all(m));

    Mint res = 1;
    int ia = 0, ib = 0;
    while(ia + ib < k) {
        if(ia == sz(p)) {
            if(ia + ib == k - 1) {
                ia--;
                res /= p[ia];
            }

            res *= (Mint) (m[ib] * m[ib + 1]);
            ib += 2;
        } else if(ib == sz(m) || ib == sz(m) - 1) {
            res *= (Mint) p[ia];
            ia++;
        } else if(ia + ib == k - 1) {
            res *= (Mint) p[ia];
            ia++;
        } else if(ia == sz(p) - 1) {
            if(p[ia] > m[ib] * m[ib + 1]) {
                res *= (Mint) p[ia];
                ia++;
            } else {
                res *= (Mint) (m[ib] * m[ib + 1]);
                ib += 2;
            }
        } else {
            if(p[ia] * p[ia + 1] > m[ib] * m[ib + 1]) {
                res *= (Mint) p[ia];
                ia++;
            } else {
                res *= (Mint) (m[ib] * m[ib + 1]);
                ib += 2;
            }
        }
    }

    pf(res);
}

int main() {
    go();
    int t;t = 1;
    while(t--) solve();
    return 0;
}
