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
const int MAX = 1e6 + 5;
int cnt[MAX];
void solve() {
    int m, q, n;
    cin >> m >> q >> n;

    vector<int> v(n);
    forIn(v, n);

    memset(cnt, 0, sizeof(cnt));
    for(int i = 0;i < n;i++) {
        cnt[v[i]]++;
    }

    int mx = 0;
    for(int i = 1;i < MAX;i++) {
        int curr = i, now = 0, val = q;
        while(curr >= 1 && val >= 0) {
            now += cnt[curr];
            curr -= m;val--;
        }

        curr = i, val = q;
        while(curr < MAX && val >= 0) {
            now += cnt[curr];
            curr += m, val--;
        }

        mx = max(mx, now - cnt[i]);
    }

    pf(mx);
}

int main() {
    go();
    solve();
    return 0;
}