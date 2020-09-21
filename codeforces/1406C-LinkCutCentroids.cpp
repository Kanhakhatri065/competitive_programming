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
const int MAX = 1e5 + 5;
vector<int> adj[MAX];

vector<int> Centroid(vector<int> g[], int n) {
    vector<int> centroid;
    vector<int> sz(n);
    function<void (int, int)> dfs = [&](int u, int prev) {
            sz[u] = 1;
            bool is_centroid = true;
            for (auto v : g[u]) if (v != prev) {
                    dfs(v, u);
                    sz[u] += sz[v];
                    if (sz[v] > n / 2) is_centroid = false;
            }
            if (n - sz[u] > n / 2) is_centroid = false;
            if (is_centroid) centroid.push_back(u);
    };

    dfs(0, -1);

    return centroid;
}

void solve() {
    int n;
    sc(n);

    int src, dest;
    for(int i = 1;i < n;i++) {
        cin >> src >> dest;
        src--, dest--;
        adj[src].pb(dest);
        adj[dest].pb(src);
    }


    vector<int> centor = Centroid(adj, n);
    if(int(centor.size()) == 1) {
        cout << centor[0] + 1 << " " << adj[centor[0]][0] + 1 << endl;
        cout << centor[0] + 1 << " " << adj[centor[0]][0] + 1 << endl;
    } else {
        for(int i = 0;i < int(adj[centor[1]].size());i++) {
            if(adj[centor[1]][i] != centor[0]) {
                dest = adj[centor[1]][i];
                break;
            }
        }
        cout << centor[1] + 1 << " " << dest + 1 << endl;
        cout << centor[0] + 1 << " " << dest + 1 << endl;
    }

    for(int i = 0;i < n;i++) {
        adj[i].clear();
    }
}

int main() {
    go();
    int t;
    sc(t);

    while(t--) {
        solve();
    }

    return 0;
}