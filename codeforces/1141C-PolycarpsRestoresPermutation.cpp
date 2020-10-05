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
void solve() {
    int n;
    sc(n);

    vector<int> q(n - 1);
    ll sum = 0, min_val = 0;
    for(int i = 0;i < n - 1;i++) {
        sc(q[i]);
        sum += q[i];

        min_val = min(min_val, sum);
    }

    vector<ll> p(n);
    p[0] = 1 - min_val;
    for(int i = 1;i < n;i++) {
        p[i] = p[i - 1] + q[i - 1];
    }

    bool ok = true;
    for(int i = 0;i < n;i++) {
        if(p[i] < 1 || p[i] > n) {
            ok = false;
        }
    }

    if(ok) {
        ok = (set<ll>(all(p)).size()) == n;
    }

    if(ok) {
        vpnt(p);
    } else {
        pf(-1);
    }
}

int main() {
    go();
    solve();
    return 0;
}