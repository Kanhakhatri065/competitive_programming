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
    int n, d;
    cin >> n >> d;

    vector<vector<int>> v(n, vector<int>(d));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < d;j++) {
            sc(v[i][j]);
        }
    }

    vector<ll> store;
    ll sum = 0;
    for(int i = 0;i < n - 1;i++) {
        for(int j = i + 1;j < n;j++) {
            sum = 0;
            for(int k = 0;k < d;k++) {
                sum += abs(v[i][k] - v[j][k]);
            }
            store.pb(sum);
        }
    }

    //vpnt(store);

    if(store.empty()) {
        pf(0);
    } else {
        sort(all(store), greater<ll>());
        sum = 0;
        for(int i = 0;i < n - 1;i++) {
            sum += store[i];
        }

        pf(sum);
    }
}

int main() {
    go();
    solve();
    return 0;
}