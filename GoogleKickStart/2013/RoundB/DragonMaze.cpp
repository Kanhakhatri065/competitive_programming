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
const int N = 105;
/*-------------- Push your limits here ---------------------------*/
int n, m;
int sx, sy, ex, ey;
vector<vector<int>> maze;
int visited[N][N];
void solve() {
    cin >> n >> m;
    cin >> sx >> sy >> ex >> ey;

    maze.clear();
    maze.resize(n, vector<int>(m, 0));

    for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) cin >> maze[i][j];
    
    mem(visited, -1);

    set<pi> posvec1, posvec2, *currSet, *nextSet;
    posvec1.insert({sx, sy});
    visited[sx][sy] = maze[sx][sy];
    maze[sx][sy] = -1;
    currSet = &posvec1;
    nextSet = &posvec2;

    while(!currSet->empty()) {
        nextSet->clear();
        for(auto it = currSet->begin();it != currSet->end();it++) {
            int row, col;
            row = it->ff - 1;
            col = it->ss;

            if(row >= 0 && maze[row][col] != -1) {
                ckmax(visited[row][col], visited[it->ff][it->ss] + maze[row][col]);
                nextSet->insert({row, col});
            }

            row = it->ff + 1;
            col = it->ss;
            if(row < n && maze[row][col] != -1) {
                ckmax(visited[row][col], visited[it->ff][it->ss] + maze[row][col]);
                nextSet->insert({row, col});
            }

            row = it->ff;
            col = it->ss - 1;
            if(col >= 0 && maze[row][col] != -1) {
                ckmax(visited[row][col], visited[it->ff][it->ss] + maze[row][col]);
                nextSet->insert({row, col});
            }

            row = it->ff;
            col = it->ss + 1;
            if(col < m && maze[row][col] != -1) {
                ckmax(visited[row][col], visited[it->ff][it->ss] + maze[row][col]);
                nextSet->insert({row, col});
            }
        }

        for(auto it = nextSet->begin();it != nextSet->end();it++) {
            maze[it->ff][it->ss] = -1;
        }

        swap(currSet, nextSet);
    }

    
    // pf("Printing visited array after : ");
    // for(int i = 0;i < n;i++) {
    //     for(int j = 0;j < m;j++) {
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    if(visited[ex][ey] < 0) pf("Mission Impossible.");
    else pf(visited[ex][ey]);
}

int main() {
    go();
    mcsolve
    return 0;
}
