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

    vector<int> v(n);
    forIn(v, n);

    vector<int> pre(n), suf(n);

    pre[0] = v[0];
    for(int i = 1;i < n;i++) {
        pre[i] = v[i] | pre[i - 1];
    }

    suf[n - 1] = v[n - 1];
    for(int i = n - 2;i >= 0;i--) {
        suf[i] = v[i] | suf[i + 1];
    }

    int idx = 0, ans = -1;
    for(int i = 0;i < n;i++) {
        int x = 0;

        if(i > 0) {
            x |= pre[i - 1];
        }

        if(i < n - 1) {
            x |= suf[i + 1];
        }

        int cur = v[i] - (x & v[i]);
        if(cur > ans) {
            ans = cur;
            idx = i;
        }
    }

    swap(v[0], v[idx]);
    vpnt(v);
}

int main() {
    go();
    solve();
    return 0;
}