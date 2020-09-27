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
    int cnt = 0;

    int arr[k][26];
    memset(arr, 0, sizeof(arr));

    for(int i = 0;i < k;i++) {
        for(int j = i;j < n;j += k) {
            arr[i][s[j] - 'a']++;
        }
    }

    int mx = 0, pos;
    if(k & 1) {
        for(int i = 0;i < k / 2;i++) {
            mx = arr[i][0] + arr[k - i - 1][0];
            pos = 0;
            for(int j = 0;j < 26;j++) {
                if(mx < (arr[i][j] + arr[k - i - 1][j])) {
                    mx = arr[i][j] + arr[k - i - 1][j];
                    pos = j;
                }
            }

            for(int j = 0;j < 26;j++) {
                if(pos != j) {
                    cnt += (arr[i][j] + arr[k - i - 1][j]);
                }
            }
        }

        mx = arr[k / 2][0], pos = 0;
        for(int j = 0;j < 26;j++) {
            if(mx < arr[k / 2][j]) {
                mx = arr[k / 2][j];
                pos = j;
            }
        }

        for(int j = 0;j < 26;j++) {
            if(pos != j) {
                cnt += arr[k / 2][j];
            }
        }
    } else {
        for(int i = 0;i < k / 2;i++) {
            mx = arr[i][0] + arr[k - i - 1][0];
            pos = 0;
            for(int j = 0;j < 26;j++) {
                if(mx < (arr[i][j] + arr[k - i - 1][j])) {
                    mx = arr[i][j] + arr[k - i - 1][j];
                    pos = j;
                }
            }

            for(int j = 0;j < 26;j++) {
                if(pos != j) {
                    cnt += (arr[i][j] + arr[k - i - 1][j]);
                }
            }
        }
    }

    pf(cnt);
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