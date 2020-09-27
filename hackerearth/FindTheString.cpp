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

    char arr[n][m];
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            sc(arr[i][j]);
        }
    }

    string str;
    sc(str);

    int k = int(str.size());

    vector<map<char, int>> v(n);
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            v[i][arr[i][j]]++;
        }
    }

    bool flag = true;
    int cnt = 0;
    while(cnt < k) {
        for(int i = 0;i < n;i++) {
            if(cnt == k) {
                break;
            }

            if(v[i][str[cnt]]) {
                v[i][str[cnt]]--;
                cnt++;
            } else {
                flag = false;
                break;
            }
        }

        if(!flag) {
            break;
        }
    }

    if(flag) {
        pf("Yes");
    } else {
        pf("No");
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