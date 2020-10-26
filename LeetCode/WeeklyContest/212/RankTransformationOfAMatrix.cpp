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
class Solution {
public:
    int f[1005];
    int Max[1005];    
    int Find(int x) {
        if(f[x] == x) {
            return x;
        }

        return f[x] = Find(f[x]);
    }

    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int n = int(matrix.size());
        int m = int(matrix[0].size());

        vector<vector<int>> ans(n, vector<int>(m));
        map<int, vector<pair<int, int>>> mp;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                mp[matrix[i][j]].pb({i, j});
            }
        }

        int col[505], row[505];
        fill(col, col + 505, 0);
        fill(row, row + 505, 0);

        for(auto &it : mp) {
            for(auto &it2 : it.second) {
                f[it2.first] = it2.first;
                Max[it2.first] = row[it2.first];
                f[it2.second + n] = it2.second + n;
                Max[it2.second + n] = col[it2.second];
            }

            for(auto &it2 : it.second) {
                int a = Find(it2.first), b = Find(it2.second + n);
                if(a != b) {
                    f[a] = b;
                    Max[b] = max(Max[b], Max[a]);
                }
            }

            for(auto it2 : it.second) {
                ans[it2.first][it2.second] = Max[Find(it2.first)] + 1;
                row[it2.first] = col[it2.second] = ans[it2.first][it2.second];
            }
        }

        return ans;
    }
};  