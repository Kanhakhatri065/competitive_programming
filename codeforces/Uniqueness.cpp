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
    sc(n);


    vector<int> v(n, 0);
    forIn(v, n);

    int ans = n - 1;
    for(int i = 0;i < n;i++) {
        int flag = 1;
        map<int, int> m;
        for(int j = 0;j < i;j++) {
            m[v[j]]++;
            if(m[v[j]] == 2) {
                flag = 0;
                break;
            }
        }

        int count = n;
        for(int j = n - 1;j >= i;j--) {
            m[v[j]]++;
            if(m[v[j]] == 1) {
                count = j;
            } else {
                break;
            }
        }

        if(flag) {
            ans = min(count - i, ans);
        }
    }

    pf(ans);
}

int main() {
    go();
    solve();
    return 0;
}