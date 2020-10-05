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
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    forIn(v, n);

    map<int, int> mp;
    for(int i = 0;i < n;i++) {
        mp[v[i]]++;
    }

    if(k == 1) {
        if(int(mp.size()) > 1) {
            pf(-1);
        } else {
            pf(1);
        }

        return;
    }

    if(k >= int(mp.size())) {
        pf(1);
    } else {
        vector<int> store;
        for(auto it : mp) {
            store.pb(it.first);
        }

        set<int> check;
        for(int i = k;i < int(store.size());i++) {
            check.insert(store[i] - store[k - 1]);
        }

        int check_size = int(check.size());
        int ans = check_size / (k - 1);
        if(check_size % (k - 1)) {
            ans++;
        }

        pf(ans + 1);
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