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
#ifdef LOCAL
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
}
const int MOD = 1e9 + 7;
const int N = 1e7 + 1;
bool sieve[N];
int dp[N];
void precomputation() {
    memset(sieve, true, sizeof(sieve));
    sieve[0] = sieve[1] = false;
    for(int i = 2;i < N;i++) {
        if(sieve[i]) for(int j = 2 * i;j < N;j += i) sieve[j] = false;
    }

    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 2;
    dp[5] = 3;
    for(int i = 6;i < N;i++) {
        dp[i] = dp[i - 1];

        if(sieve[i]) dp[i]++;

        if(i % 2 == 0) {
            if(sieve[i / 2]) {
                dp[i]--;
            }
        }
    }
}

void solve() {
    int x;cin >> x;
    pf(dp[x]);
}

int main() {
    go();
    precomputation();
    int t;cin >> t;
    while(t--) solve();
    return 0;
}