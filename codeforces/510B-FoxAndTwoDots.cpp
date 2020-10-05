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
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int MAX = 55;
bool visited[MAX][MAX];
char graph[MAX][MAX];
int n, m;

bool findCycle = false;

void dfs(int x, int y, int fromX, int fromY, char needColor) {
    if(x < 0 || x >= n || y < 0 || y >= m) {
        return;
    }

    if(graph[x][y] != needColor) {
        return;
    }

    if(visited[x][y]) {
        findCycle = true;
        return;
    }

    visited[x][y] = true;
    for(int i = 0;i < 4;i++) {
        if(x + dx[i] == fromX && y + dy[i] == fromY) {
            continue;
        }

        dfs(x + dx[i], y + dy[i], x, y, needColor);
    }
}

void solve() {
    cin >> n >> m;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            sc(graph[i][j]);
        }
    }

    memset(visited, 0, sizeof(visited));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(!visited[i][j]) {
                dfs(i, j, -1, -1, graph[i][j]);
            }
        }
    }

    cout << (findCycle ? "Yes" : "No") << endl;
}

int main() {
    go();
    solve();
    return 0;
}