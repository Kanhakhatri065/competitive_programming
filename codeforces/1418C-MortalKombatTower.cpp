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
const int INF = 1e9 + 5;

void solve() {
    int n;
    sc(n);

    vector<int> v(n);
    forIn(v, n);

    int ans = 0;
    ans += (v[0] == 1);
    for(int i = 1;i < n;i++) {
        if(v[i] == 0) {
            continue;
        }

        int j = i;
        while(j < n && v[j] == 1) {
            j++;
        }

        ans += (j - i) / 3;
        i = j - 1;
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