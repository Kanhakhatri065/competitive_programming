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
bool getBit(ll val, ll pos) {
    return (bool)(val & (1LL << pos));
}

void solve() {
    int n;
    sc(n);

    vector<ll> a(n), b(n), c(n);
    forIn(a, n);
    forIn(b, n);
    forIn(c, n);
    
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ll tmp = 0;
        bool flg = false;
        for(ll j = 0; j < 30; j++){
            ll mx1 = getBit(a[i], j) ^ getBit(b[i], j);
            ll mx2 = getBit(a[i], j) ^ getBit(b[i], j) ^ getBit(c[i], j);
            tmp += (1LL << j) * max(mx1, mx2);
            if(mx2 && getBit(c[i], j)) flg = true;
        }
        if(!flg){
            ll lstSetbit = 0;
            while(getBit(c[i], lstSetbit) == 0) lstSetbit++;
            if(getBit(tmp, lstSetbit) == 0) assert(false);
            tmp -= (1LL << lstSetbit);
        }
        ans += tmp;
    }

    pf(ans);
}   

int main() {
    go();
    solve();
    return 0;
}