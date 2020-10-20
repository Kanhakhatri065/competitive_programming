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
    int n, m, k;
    cin >> n >> m >> k;

    if(n == 3 && m == 3 && k == 3) {
        for(int i = 0;i < 3;i++) {
            cout << "3";
            for(int j = 0;j < 3;j++) {
                cout << " " << (i + 1) << " " << (j + 1);
            }
            cout << endl;
        }

        return;
    }

    vector<pair<int, int>> path;
    int x = 0, y = 0, dir = 1;
    path.pb({x + 1, y + 1});
    while(true) {
        y += dir;
        if(y == m) {
            dir *= -1;
            y = m - 1;
            x++;
        }

        if(y == -1) {
            dir *= -1;
            y = 0;
            x++;
        }

        if(x == n) {
            break;
        }
        
        path.pb({x + 1, y + 1});
    }

    for(int i = 0;i < (k - 1);i++) {
        cout << "2";
        cout << " " << path[2 * i].first << " " << path[2 * i].second;
        cout << " " << path[2 * i + 1].first << " " << path[2 * i + 1].second;
        cout << endl;
    }

    cout << (int(path.size()) - 2 * (k - 1));
    for(int i = 2 * (k - 1);i < int(path.size());i++) {
        cout << " " << path[i].first << " " << path[i].second;
    }
    cout << endl;
}

int main() {
    go();
    solve();
    return 0;
}