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
const int N = 1005;
char board[N][N];
bool destroyed[N][N];
int n;

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};
void solve() {
    cin >> n;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            sc(board[i][j]);
        }
    }

    memset(destroyed, 0, sizeof(destroyed));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            if(board[i][j] == 'K') {
                for(int k = 0;k < 8;k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if(x >= 0 && x < n && y >= 0 && y < n) {
                        if(board[x][y] == '*') {
                            destroyed[x][y] = 1;
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0;i < n - 1;i++) {
        for(int j = 0;j < n;j++) {
            if(board[i][j] == '*') {
                if(destroyed[i][j] == 0) {
                    if(j + 1 < n && board[i + 1][j + 1] == '-') {
                        board[i + 1][j + 1] = 'X';
                        destroyed[i][j] = 1;
                        
                        if(j + 2 < n) {
                            //single pawn destroying two pieces
                            destroyed[i][j + 2] = 1;
                        }

                        ans++;
                    } else if(j - 1 >= 0 && board[i + 1][j - 1] == '-') {
                        board[i + 1][j - 1] = 'X';
                        destroyed[i][j] = 1;
                        ans++;
                    }
                }
            }
        }
    }

    bool flag = true;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            if(board[i][j] == '*') {
                if(!destroyed[i][j]) {
                    flag = false;
                    break;
                }
            }
        }
    }

    flag ? pf(ans) : pf(-1);
}

int main() {
    go();
    solve();
    return 0;
}