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
const int MAX = 1e5 + 5;
int cnt[MAX];
void solve() {
    int n;
    sc(n);

    vector<int> v(n);
    forIn(v, n);

    memset(cnt, 0, sizeof(cnt));
    for(int i = 0;i < n;i++) {
        cnt[v[i]]++;
    }

    bool flag = true;
    int ans = 0, c = 0, j = 0;
    for(int i = 1;i <= n;i++) {
        while(cnt[j] == 0) {
            j++;
        }

        cnt[j]--;
        if(j - c <= 0) {
            flag = false;
            break;
        }

        if(i % 6 == 0 && i != 0) {
            c++;
        }
        c++;
        ans++;
    }

    if(flag) {
        pf("Rick now go and save Carl and Judas");
    } else {
        pf("Goodbye Rick");
        pf(ans);
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