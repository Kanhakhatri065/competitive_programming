/*
    I love the sound you make when you shut up.
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
/*----typedefs--------*/
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
/*--------test-stuff--------------------*/
#define ssolve solve();
#define msolve int T;cin >> T;while(T--) {solve();}
#define mcsolve int T;cin >> T;for(int tt = 1;tt <= T;tt++) {cout << "Case #" << tt << ": ";solve();}
/*-------- movement in a 2D array ------*/
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
/*----------------------------------------------------------------*/
const int MOD = 1e9 + 7;
const int N = 50;
/*-------------- Push your limits here ---------------------------*/
int g[50][50], n, m;
bool used[50];

vector<int> cur;
vector<vector<int>> c[50];

void dfs(int v) {
    used[v] = true;
    cur.pb(v);

    for(int i = 1;i <= n;i++) if(g[v][i] && !used[i]) dfs(i); 
}

void solve() {
    mem(g, 0);
    mem(used, 0);

    cin >> n >> m;

    for(int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;

        g[a][b] = g[b][a] = 1;
    }    

    for(int i = 1;i <= n;i++) {
        if(!used[i]) {
            cur.clear();
            dfs(i);
            c[sz(cur)].pb(cur);
        }
    }

    vector<vector<int>> out = c[3];

    for(int i = 4;i < 50;i++) {
        if(sz(c[i]) != 0) {
            pf(-1);
            return;
        }
    }

    if(sz(c[2]) > sz(c[1])) {
        pf(-1);
        return;
    }

    for(int i = 0;i < sz(c[2]);i++) {
        vector<int> tout;
        tout.pb(c[2][i][0]);
        tout.pb(c[2][i][1]);
        tout.pb(c[1][i][0]);
        out.pb(tout);
    }

    for(int i = sz(c[2]);i < sz(c[1]);i += 3) {
        vector<int> tout;
        for(int j = 0;j < 3;j++) {
            tout.pb(c[1][i + j][0]);
        }
        out.pb(tout);
    }

    for(int i = 0;i < n / 3;i++) {
        for(int j = 0;j < 3;j++) {
            cout << out[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    go();
    ssolve
    return 0;
}