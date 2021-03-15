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
const int N = 1e5 + 5;
const ll INF = 1LL << 62;
/*-------------- Push your limits here ---------------------------*/
int n, m;
vector<pair<ll, ll>> adj[N];
void solve() {
    cin >> n >> m;
    for(int i = 0;i < m;i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
    }

    vector<ll> dist(n + 1, INF), mn(n + 1, INF), mx(n + 1, 0), cnt(n + 1, 0);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    dist[1] = mn[1] = mx[1] = 0;
    cnt[1] = 1;

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if(d > dist[u]) continue;
        for(auto [v, w] : adj[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u];
                mn[v] = mn[u] + 1;
                mx[v] = mx[u] + 1;
                pq.push({dist[v], v});
            } else if(dist[v] == dist[u] + w) {
                cnt[v] = (cnt[v] + cnt[u]) % MOD;
                ckmin(mn[v], mn[u] + 1);
                ckmax(mx[v], mx[u] + 1);
            }
        }
    }

    cout << dist[n] << " " << cnt[n] << " " << mn[n] << " " << mx[n] << endl;
}

int main() {
    go();
    ssolve
    return 0;
}
