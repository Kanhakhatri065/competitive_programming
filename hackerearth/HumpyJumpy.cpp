/*** I came, I saw, I conquered. ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef unsigned long long ull;
#define sc(a) cin >> a
#define pf(a) cout << a << endl
#define forIn(arr, num) for(ll i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
#define mod 1000000007
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
void go() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
/*----------------------------------------------------------------*/
int uncommon_bits(ll n, ll m) {
    bool s, t;
    int cnt = 0;
    for(int i = 0;i < 64;i++) {
        s = n | (1 << i);
        t = m | (1 << i);

        if(s ^ t) {
            cnt++;
        }
    }

    return cnt;
}
void solve() {
    int n;
    sc(n);

    vector<ll> v(n);
    forIn(v, n);

    vector<ll> nxt(n, 0);
    stack<ll> s;

    s.push(0);
    for(int i = 1;i < n;i++) {
        while(!s.empty() && v[i] > v[s.top()]) {
            nxt[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    while(!s.empty()) {
        nxt[s.top()] = -1;
        s.pop();
    }

    vector<ll> dp(n, 0);
    ll ans = 0;
    for(int i = n - 1;i >= 0;i--) {
        if(nxt[i] == -1) {
            dp[i] = v[i];
            ans = max(ans, dp[i]);
            continue;
        }

        dp[i] = v[i] ^ dp[nxt[i]];
        ans = max(ans, dp[i]);
    }

    pf(ans);
}

int main() {
    go();
    solve();
    return 0;
}