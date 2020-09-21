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
int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 }; 
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 }; 
int board[11][11];
int ans;
bool isValid(int n, int m) {
    if(n > 10 || n < 1 || m > 10 || m < 1) {
        return false;
    }

    return true;
}

void rec(int n, int m, int k) {
    if(k == 0) {
        if(board[n][m] == 0) {
            ans++;
        }
        board[n][m] = 1;
        return;
    }

    for(int i = 0;i < 8;i++) {
        if(isValid(n + dx[i], m + dy[i])) {
            rec(n + dx[i], m + dy[i], k - 1);
        }
    }
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    ans = 0;
    memset(board, 0, sizeof(board));
    rec(n, m, k);

    pf(ans);
}

int main() {
    go();
    solve();
    return 0;
}