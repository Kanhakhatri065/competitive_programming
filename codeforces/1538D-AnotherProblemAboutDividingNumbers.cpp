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
const int N = 1e5 + 5;

bool sieve[N];
vector<ll> primes;

void precomputation() {
    fill(sieve, sieve + N, true);
    sieve[0] = sieve[1] = false;

    for(int i = 2;i < N;i++) {
        if(sieve[i]) {
            primes.pb(1LL * i);
            for(int j = 2 * i;j < N;j += i) sieve[j] = false;
        }
    }
}

int count(ll n) {
    int ans = 0;
    for(auto p : primes) {
        if(p * p > n) {
            continue;
        }

        while(n % p == 0) {
            ans++;
            n /= p;
        }
    }

    if(n > 1) {
        ans++;
    }

    return ans;
}

void solve() {
    ll a, b, k;
    cin >> a >> b >> k;

    if(k == 1) {
        if(a == b) {
            pf("NO");
        } else if(a % b == 0 || b % a == 0) {
            pf("YES");
        } else {
            pf("NO");
        }
    } else {
        int cnt = count(a) + count(b);

        if(k <= cnt) {
            pf("YES");
        } else {
            pf("NO");
        }
    }
}

int main() {
    go();
    int t;cin >> t;
    precomputation();
    while(t--) solve();
    return 0;
}