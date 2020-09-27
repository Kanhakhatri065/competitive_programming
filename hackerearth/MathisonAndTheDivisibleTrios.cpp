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
    int n, m;
    cin >> n >> m;

    int cnt[m];
    memset(cnt, 0, sizeof(cnt));

    ll p;
    for(int i = 0;i < n;i++) {
        cin >> p;
        cnt[p - (p / m) * m]++;
    }

    ll ans = 0;
    for(int i = 0;i < m;i++) {
        if(cnt[i] == 0) {
            continue;
        }

        for(int j = i;j < m;j++) {
            if(cnt[j] == 0) {
                continue;
            }

            int k = m + m - i - j;
            if(k == 2 * m) {
                k = 0;
            }

            if(k >= m) {
                k -= m;
            }

            if(k < j || cnt[k] == 0) {
                continue;
            } else if(i == j && j == k) {
                ans += (cnt[i] - 1) * (cnt[i] - 2) * cnt[i] / 6;
            } else if(i == j) {
                ans += (cnt[k]) * (cnt[i] - 1) * cnt[i] / 2;
            } else if(j == k) {
                ans += (cnt[i]) * (cnt[j] - 1) * (cnt[j]) / 2;
            } else {
                ans += cnt[i] * cnt[j] * cnt[k];
            }
        }
    }

    pf(ans);
}

int main() {
    go();
    solve();
    return 0;
}