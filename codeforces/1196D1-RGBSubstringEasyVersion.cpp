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

    string s;
    sc(s);

    string check1 = "", check2 = "", check3 = "";
    for(int i = 0;i < k;i++) {
        if(i % 3 == 0) {
            check1 += 'R';
            check2 += 'G';
            check3 += 'B';
        } else if(i % 3 == 1) {
            check1 += 'G';
            check2 += 'B';
            check3 += 'R';
        } else {
            check1 += 'B';
            check2 += 'R';
            check3 += 'G';
        }
    }

    int ans = k;
    for(int i = 0;i <= (n - k);i++) {
        string tmp = s.substr(i, k);

        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for(int j = 0;j < k;j++) {
            if(tmp[j] != check1[j]) {
                cnt1++;
            }

            if(tmp[j] != check2[j]) {
                cnt2++;
            }

            if(tmp[j] != check3[j]) {
                cnt3++;
            }
        }

        ans = min({ans, cnt1, cnt2, cnt3});
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