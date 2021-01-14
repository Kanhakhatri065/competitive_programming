#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MOD = 998244353;
const int MAXN = (1 << 20);
template<class T, class T1> int chkmin(T &x, const T1 &y) { return x > y ? x = y, 1 : 0; }
template<class T, class T1> int chkmax(T &x, const T1 &y) { return x < y ? x = y, 1 : 0; }

int pw(int x, int p) {
    int r = 1;
    while(p) {
        if(p & 1) r = (1LL * r * x) % MOD;
        x = (1LL * x * x) % MOD;
        p >>= 1;
    }

    return r;
}

int n, m, k;

void solve_1() {
    int ik_c = (1 - pw(k, MOD - 2) + MOD) % MOD;
    int ans = (1LL + 1LL * ik_c * (n - 1)) % MOD;
    cout << ans << endl;
}

void fix(int &x) {
    if(x >= MOD) x -= MOD;
    if(x < 0) x += MOD;
}

void solve_2() {
    int ik = pw(k, MOD - 2);
    // We will use Euler's Theorem:
    // v - e + f = 1 + k
    // E[k] = 2 * n - 1 - E[e] + E[f]
    // E[e] = ik * (3 * n - 1)

    int ans = 2 * n - 1;
    ans -= 1LL * ik * (3LL * n - 2) % MOD;
    fix(ans);

    int Ef = 1LL * ik * ik % MOD;
    Ef = 1LL * Ef * ik % MOD;
    Ef = 1LL * Ef * (n - 1) % MOD;
    Ef += 1; // main_face
    ans += Ef;
    fix(ans);
    cout << ans << endl;
}

void solve() {
    cin >> m >> n >> k;

    if(m == 1) solve_1();
    else solve_2();
}

int main() {
    solve();
    return 0;
}
