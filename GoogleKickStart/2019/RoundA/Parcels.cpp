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
const int INF = 1e9;
const int N = 255;
/*-------------- Push your limits here ---------------------------*/
int n, m;
char s[N][N];
int d[N][N];

void bfs() {
    mem(d, -1);
    queue<pi> q;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(s[i][j]) {
                d[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while(!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for(int i = 0;i < 4;i++) {
            int tx = x + d4i[i], ty = y + d4j[i];
            if(min(tx, ty) <= 0 || tx > n || ty > m) continue;
            if(d[tx][ty] != -1) continue;
            d[tx][ty] = d[x][y] + 1;
            q.push({tx, ty});
        }
    }

    for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) if(d[i][j] == -1) d[i][j] = INF;
}

bool can(int x) {
    int plus_max = INF, plus_min = -INF, minus_max = INF, minus_min = -INF;
    bool ok = true;

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(d[i][j] <= x) continue;
            ckmin(plus_max, i + j + x);
            ckmax(plus_min, i + j - x);
            ckmin(minus_max, i - j + x);
            ckmax(minus_min, i - j - x);
            ok = false;
        }
    }

    if(ok) return true;
    
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            int plus = i + j, minus = i - j;
            if(plus_min <= plus && plus <= plus_max && minus_min <= minus && minus <= minus_max) {
                return true;
            }
        }
    }

    return false;
}

void solve() {
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> s[i][j];
            s[i][j] -= '0';
        }
    }

    bfs();
    int lo = 0, hi = INF;
    while(lo < hi) {
        int mid = (lo + hi) >> 1;
        if(can(mid)) hi = mid;
        else lo = mid + 1;
    }

    pf(hi);
}

int main() {
    //go();
    mcsolve
    return 0;
}
