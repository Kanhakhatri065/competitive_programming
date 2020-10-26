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
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = int(heights.size());
        int m = int(heights[0].size());   

        int mx = 1e9, mn = -1;
        while(mx > (mn + 1)) {
            int mid = (mx + mn) / 2;
            queue<pair<int, int>> q;
            q.push({0, 0});
            bool visited[105][105];
            memset(visited, 0, sizeof(visited));
            visited[0][0] = 1;
            while(!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();
                int X[4] = {0, 0, 1, -1};
                int Y[4] = {1, -1, 0, 0};

                for(int k = 0;k < 4;k++) {
                    int x = p.first + X[k], y = p.second + Y[k];
                    if(x >= 0 && x < n && y >= 0 && y < m) {
                        if(abs(heights[x][y] - heights[p.first][p.second]) <= mid && visited[x][y] == 0) {
                            q.push({x, y});
                            visited[x][y] = 1;
                        }
                    }
                }
            }
            
            if(visited[n - 1][m - 1]) {
                mx = mid;
            } else {
                mn = mid;
            }
        }

        return mx;
    }
};
