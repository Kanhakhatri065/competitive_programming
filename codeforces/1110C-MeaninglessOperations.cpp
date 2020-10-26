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
#define int long long
int largest_divisor(int n) {
    int ans = 1;
    for(int i = sqrt(n);i >= 2;i--) {
        if(n % i == 0) {
            ans = max({ans, i, n / i});
        }
    }

    return ans;
}   

void solve() {
    int n;
    sc(n);

    int q = n;
    bool flag = false;
    int pos = 0, m = -1;
    while(q > 0) {
        m++;
        if(!(q & 1)) {
            flag = true;
        } else {
            pos = m;
        }
        q >>= 1;
    }

    int ans = 0;
    if(flag) {
        for(int i = 0;i <= pos;i++) {
            ans += pow(2, i);
        }

        pf(ans);
    } else {
        pf(largest_divisor(n));
    }
}

int32_t main() {
    go();
    int t;
    sc(t);

    while(t--) {
        solve();
    }

    return 0;
}