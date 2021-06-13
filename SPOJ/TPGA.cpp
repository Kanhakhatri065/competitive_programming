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

int a[N], fact[N], ft[N];
int getSum(int idx) {
    int sum = 0;
    while(idx > 0) {
        sum += ft[idx];
        idx -= (idx & (-idx));
    }
    return sum;
}

void update(int n, int idx) {
    while(idx <= n) {
        ft[idx]++;
        idx += (idx & (-idx));
    }
}

void initfact() {
    fact[0] = 1;
    for(int i = 1;i < N;i++) {
        fact[i] = (1LL * i * fact[i - 1]) % MOD;
    }
}

void solve() {
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    memset(ft, 0, sizeof(ft));
    int ans = 1;
    for(int i = 1;i <= n;i++) {
        int curr = getSum(a[i]);
        ans = (ans + ((1LL * (a[i] - curr - 1)) * fact[n - i]) % MOD) % MOD;
        update(n, a[i]);
    }

    pf(ans);
}

int main() {
    go();
    initfact();
    int t;cin >> t;
    while(t--) solve();
    return 0;
}