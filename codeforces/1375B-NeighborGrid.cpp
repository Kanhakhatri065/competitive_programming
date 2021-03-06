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
const int MAX = 305;
int mat[MAX][MAX];

void solve() {
    int n, m;
    cin >> n >> m;

    bool flag = true;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            sc(mat[i][j]);
        }
    }

    for(int i = 0;i < n && flag;i++) {
        for(int j = 0;j < m;j++) {
            if((i == 0 || i == n - 1) && (j == m - 1 || j == 0)) {
                if(mat[i][j] > 2) {
                    flag = false;
                    break;
                } else {
                    mat[i][j] = 2;
                }
            } else if(i == 0 || j == 0 || i == n - 1 ||j == m - 1) {
                if(mat[i][j] > 3) {
                    flag = false;
                    break;
                } else {
                    mat[i][j] = 3;
                }
            } else {
                if(mat[i][j] > 4)  {
                    flag = false;
                    break;
                } else {
                    mat[i][j] = 4;
                }
            }
        }
    }

    if(flag) {
        yes;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        no;
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