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
    string s;
    sc(s);

    int n = int(s.size());

    string kick = "KICK";
    vector<int> kick_store;
    for(int i = 0;i <= (n - 4);i++) {
        string tmp = s.substr(i, 4);
        if(tmp == kick) {
            kick_store.pb(i);
        }
    }

    string start = "START";
    vector<int> start_store;
    for(int i = 0;i <= (n - 5);i++) {
        string tmp = s.substr(i, 5);
        if(tmp == start) {
            start_store.pb(i);
        }
    }

    ll cnt = 0;
    for(int i : kick_store) {
        for(int j : start_store) {
            if(i < j) {
                cnt++;
            }
        }
    }

    pf(cnt);
}

int main() {
    go();
    int t;
    sc(t);

    for(int tt = 1;tt <= t;tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }

    return 0;
}