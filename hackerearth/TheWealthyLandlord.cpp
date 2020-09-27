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
const int MAX = 1005;
int arr[MAX][MAX];
void solve() {
    memset(arr, 0, sizeof(arr));
    int n;
    sc(n);

    vector<pair<int, int>> x_range(n), y_range(n);
    vector<int> prices(n);
    int mn_x = INT_MAX, mx_x = INT_MIN, mn_y = INT_MAX, mx_y = INT_MIN;
    for(int i = 0;i < n;i++) {
        cin >> x_range[i].first >> y_range[i].first >> x_range[i].second >> y_range[i].second >> prices[i];
        mn_x = min({mn_x, x_range[i].first, x_range[i].second});
        mx_x = max({mx_x, x_range[i].first, x_range[i].second});
        mn_y = min({mn_y, y_range[i].first, y_range[i].second});
        mx_y = max({mx_y, y_range[i].first, y_range[i].second});
    }

    for(int i = 0;i < n;i++) {
        for(int j = x_range[i].first;j <= x_range[i].second;j++) {
            for(int k = y_range[i].first;k <= y_range[i].second;k++) {
                arr[j][k]++;
            }
        }
    }

    ll sum = 0;
    for(int i = mn_x;i <= mx_x;i++) {
        for(int j = mn_y;j <= mx_y;j++) {
            if(arr[i][j] > 1) {
                for(int k = 0;k < n;k++) {
                    if(i >= x_range[k].first && i <= x_range[k].second && j >= y_range[k].first && j <= y_range[k].second) {
                        sum += prices[k];
                    }
                }
            }
        }
    }

    pf(sum);
}

int main() {
    go();
    solve();
    return 0;
}