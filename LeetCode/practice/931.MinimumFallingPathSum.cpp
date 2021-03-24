/*
    I love the sound you make when you shut up.
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
/*-------typedefs------*/
template<class T> using ordered_set = tree<T, null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update> ;
using ll = long long;
using pi = pair<int, int>;
/*-----in and out--------*/
#define pf(a) cout << a << endl
#define forIn(arr, num) for(int i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(int i = 0; i < int(ans.size()); i++) cout << ans[i] << (i + 1 < int(ans.size()) ? ' ' : '\n');
/*---useful defines------*/
#define sz(x) (int)(x).size()
#define pb push_back
#define mem(a, b) memset(a,(b), sizeof(a))
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
/*----- the binary answer of life-----*/
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
/*---checking and pushing-----*/
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
/*---- FAST I/O and file read ---*/
void go() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
}
/*-------- test-case stuff--------------*/
#define ssolve solve();
#define msolve int T;cin >> T;while(T--) {solve();}
#define mcsolve int T;cin >> T;for(int tt = 1;tt <= T;tt++) {cout << "Case #" << tt << ": ";solve();}
/*-------- movement in a 2D array ------*/
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
/*----------------------------------------------------------------*/
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
/*-------------- Push your limits here ---------------------------*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = sz(matrix);
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for(int i = n - 1;i >= 0;i--) {
            for(int j = n - 1;j >= 0;j--) {
                int x = matrix[i][j];
                int p = 0;
                if(i + 1 < n) {
                    p = dp[i + 1][j];
                    if(j - 1 >= 0) {
                        ckmin(p, dp[i + 1][j - 1]);
                    }

                    if(j + 1 < n) {
                        ckmin(p, dp[i + 1][j + 1]);
                    }
                }

                ckmin(dp[i][j], x + p);
            }
        }

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }

        int ans = *min_element(dp[0].begin(), dp[0].end());
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> v({{2, 1, 3}, {6, 5, 4}, {7, 8, 9}});
    int ans = s.minFallingPathSum(v);
    
    pf("Answer : " + to_string(ans));
    return 0;
}
