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
    int n, q;
    cin >> n >> q;

    string str;
    sc(str);

    int arr[n + 1][26];
    memset(arr, 0, sizeof(arr));
    for(int i = 1;i <= n;i++) {
        arr[i][str[i - 1] - 'a']++;
        for(int j = 0;j < 26;j++) {
            arr[i][j] += arr[i - 1][j];
        }
    }

    int temp_arr[26];
    char ans;
    int cnt, l, r, k;
    while(q--) {
        cin >> l >> r >> k;
        for(int i = 0;i < 26;i++) {
            temp_arr[i] = arr[r][i] - arr[l - 1][i];
        }

        cnt = 0;
        for(int i = 0;i < 26;i++) {
            if(cnt + temp_arr[i] >= k) {
                ans = char(i + 97);
                break;
            }
            cnt += temp_arr[i];
        }

        pf(ans);
    }
}

int main() {
    go();
    solve();
    return 0;
}