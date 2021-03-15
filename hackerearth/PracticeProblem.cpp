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
int n, q;
vector<int> par;
vector<vector<int>> adj;
vector<int> lamps;
vector<int> store;
void dfs(int u, int p) {
    if(p != -1) {
        par[u] = p;
    } 
     
    int cnt = 1;
    for(int v : adj[u]) {
        if(v == p) continue;
        dfs(v, u);
        cnt += store[v];
    }
    
    store[u] += cnt; 
 }

void update(int v) {
    bool flag = true;
    if(lamps[v] == 1) {
        flag = false;
        lamps[v] = 0;
        store[v]--;
    } else {
        flag = true;
        lamps[v] = 1;
        store[v]++;
    }
    
    for(int u = par[v];u != -1;u = par[u]) {
        if(flag) {
            store[u]++;
        } else {
            store[u]--;
        }
    }
}

void solve() {
    cin >> n >> q;
    adj.resize(n + 1);
    par.assign(n + 1, -1);
    lamps.assign(n + 1, 1);
    store.assign(n + 1, 0);

    for(int i = 1;i < n;i++) {
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    dfs(1, -1); 

    while(q--) {
        int t, v;
        cin >> t >> v;
        if(t == 1) {
            update(v);
        } else {
            pf(store[v]);
        }
    } 
}

int main() {
    //go();
    ssolve
    return 0;
}
