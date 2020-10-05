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
    cin >> n;

    vector<int> a(n), b(n), c(n);
    forIn(a, n);
    forIn(b, n);
    forIn(c, n);

    vector<set<int>> store(n);
    for(int i = 0;i < n;i++) {
        store[i].insert(a[i]);
        store[i].insert(b[i]);
        store[i].insert(c[i]);
    }

    vector<int> ans(n);
    ans[0] = *store[0].begin();
    for(int i = 1;i < n;i++) {
        for(auto it : store[i]) {
            if(it != ans[i - 1]) {
                ans[i] = it;
                break;
            }
        }
    }

    for(auto it : store[n - 1]) {
        if(it != ans[n - 2] && it != ans[0]) {
            ans[n - 1] = it;
            break;
        }
    }

    vpnt(ans);
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