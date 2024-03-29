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
const int N = 505;
char maze[N][N];
int n, m, k, e = 0, cnt = 0;
void dfs(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m || maze[x][y] != '.' || cnt == (e - k)) {
        return;
    }

    maze[x][y] = 'T';
    cnt++;

    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

void solve() {
    cin >> n >> m >> k;

    int x, y;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            sc(maze[i][j]);
            if(maze[i][j] == '.') {
                e++;
                x = i;
                y = j;
            }
        }
    }

    dfs(x, y);

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(maze[i][j] == 'T') {
                cout << '.';
            } else if(maze[i][j] == '.') {
                cout << 'X';
            } else {
                cout << '#';
            }
        }
        cout << endl;
    }
}

int main() {
    go();
    solve();
    return 0;
}