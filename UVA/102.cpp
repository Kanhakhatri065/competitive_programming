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
    int B[3], G[3], C[3];
    while(cin >> B[0]) {
        cin >> G[0] >> C[0] >> B[1] >> G[1] >> C[1] >> B[2] >> G[2] >> C[2];

        //BCG
        int mn = INT_MAX, tmp;
        string ans;
        tmp = (C[0] + G[0]) + (B[1] + G[1]) + (B[2] + C[2]);
        if(mn > tmp) {
            mn = tmp;
            ans = "BCG";
        }

        //BGC
        tmp = (C[0] + G[0]) + (B[1] + C[1]) + (B[2] + G[2]);
        if(mn > tmp) {
            mn = tmp;
            ans = "BGC";
        }

        //CBG
        tmp = (B[0] + G[0]) + (G[1] + C[1]) + (B[2] + C[2]);
        if(mn > tmp) {
            mn = tmp;
            ans = "CBG";
        }

        //CGB
        tmp = (B[0] + G[0]) + (B[1] + C[1]) + (C[2] + G[2]);
        if(mn > tmp) {
            mn = tmp;
            ans = "CGB";
        }

        //GBC
        tmp = (B[0] + C[0]) + (C[1] + G[1]) + (B[2] + G[2]);
        if(mn > tmp) {
            mn = tmp;
            ans = "GBC";
        }

        //GCB
        tmp = (B[0] + C[0]) + (B[1] + G[1]) + (C[2] + G[2]);
        if(mn > tmp) {
            mn = tmp;
            ans = "GCB";
        }

        cout << ans << " " << mn << endl;
    }
}

int main() {
    go();
    solve();
    return 0;
}