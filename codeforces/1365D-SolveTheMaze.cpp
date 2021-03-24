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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
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
void solve() {
    int n, m;
    cin >> n >> m;

    char arr[n][m];
    for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) cin >> arr[i][j];

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(arr[i][j] == 'B') {
                for(int k = 0;k < 4;k++) {
                    int x = i + d4i[k], y = j + d4j[k];
                    if(x < 0 || x >= n || y < 0 || y >= m) continue;
                    if(arr[x][y] == '.') arr[x][y] = '#';
                }
            }
        }
    }

    queue<pi> q;
    int visited[n][m];
    mem(visited, false);
    if(arr[n - 1][m - 1] == '.') {
        q.push({n - 1, m - 1});
        visited[n - 1][m - 1] = true;
    }

    while(!q.empty()) {
        int x = q.front().ff, y = q.front().ss;
        q.pop();
        for(int k = 0;k < 4;k++) {
            int nx = x + d4i[k], ny = y + d4j[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(!visited[nx][ny]) {
                if(arr[nx][ny] != '#') {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }

    bool good = true;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if((arr[i][j] == 'G' && !visited[i][j]) || (arr[i][j] == 'B' && visited[i][j])) {
                good = false;
            }
        }
    }

    good ? yes : no;
}

int main() {
    go();
    msolve
    return 0;
}
