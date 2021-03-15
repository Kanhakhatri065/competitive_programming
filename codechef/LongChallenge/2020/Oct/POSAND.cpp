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
bool isPowerOf2(int n) {
    if(n == 1) {
        return false;
    }

    while(n > 1) {
        if(n & 1) {
            return false;
        }

        n /= 2;
    }

    return true;
}

void solve() {
    int n;
    sc(n);

    if(isPowerOf2(n)) {
        pf(-1);
    } else {
        if(n == 1) {
            pf(1);
            return;
        }   

        vector<int> ans;
        ans.pb(2);
        ans.pb(3);
        ans.pb(1);

        for(int i = 4;i <= n;i++) {
            if(isPowerOf2(i)) {
                ans.pb(i + 1);
                ans.pb(i);
                i++;
            } else {
                ans.pb(i);
            }
        }

        vpnt(ans);
    }
}

int main() {
    go();
    int t;
    sc(t);

    while(t--) {
        solve();
    }
    
    return 0;
}