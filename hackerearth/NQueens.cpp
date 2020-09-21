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
bool isSafe(vector<vector<int>> &board, int idx, int col) {
    for(int i = idx - 1, left = col - 1, right = col + 1;i >= 0;i--, left--, right++) {
        if(left >= 0 && board[i][left] == 1) {
            return false;
        }

        if(right < int(board.size()) && board[i][right] == 1) {
            return false;
        }

        if(board[i][col] == 1) {
            return false;
        }
    }

    return true;
}

bool nqueens(vector<vector<int>> &board, int idx) {
    if(idx == int(board.size())) {
        return true;
    }

    for(int col = 0;col < int(board.size());col++) {
        if(isSafe(board, idx, col)) {
            board[idx][col] = 1;

            if(nqueens(board, idx + 1)) {
                return true;
            }

            board[idx][col] = 0;
        }
    }

    return false;
}

void solve() {
    int n;
    sc(n);

    vector<vector<int>> board(n, vector<int>(n, 0));
    bool flag = nqueens(board, 0);

    if(flag) {
        yes;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                cout << board[i][j] << ' ';
            }
            cout << endl;
        }
    } else {
        no;
    }
}

int main() {
    go();
    solve();
    return 0;
}