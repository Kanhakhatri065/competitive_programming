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
    ll a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    
    ll a1 = a, b1 = b, n1 = n;
    
    ll ans;
    if(a - x >= n && b - y >= n) {
        ans = min((a - n) * b, a * (b - n));
    } else if(a - x >= n && b - y < n) {
        ans = (a - n) * b;
        n -= (b - y);
        b = y;

        if(a - x >= n) {
            a -= n;
            n = 0;
        } else {
            n -= (a - x);
            a = x;
        }

        ans = min(ans, a * b);
    } else if(a - x < n && b - y >= n) {
        ans = a * (b - n);
        n -= (a - x);
        a = x;

        if(b - y >= n) {
            b -= n;
            n = 0;
        } else {
            n -= (b - y);
            b = y;
        }

        ans = min(ans, a * b);
    } else {
        if(a - x >= n) {
            a -= n;
            n = 0;
        } else {
            n -= (a - x);
            a = x;
        }
        
        if(b - y >= n) {
            b -= n;
            n = 0;
        } else {
            n -= (b - y);
            b = y;
        }
        
        if(b1 - y >= n1) {
            b1 -= n1;
            n1 = 0;
        } else {
            n1 -= (b1 - y);
            b1 = y;
        }
        
        if(a1 - x >= n1) {
            a1 -= n1;
            n1 = 0;
        } else {
            n1 -= (a1 - x);
            a1 = x;
        }

        ans = min(a * b, a1 * b1);
    }

    pf(ans);
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