#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;

int discTime;

int parent[N], L[N], R[N];
ll seg_tree[4 * N], F[N];

pair<int, int> E[N];
vector<int> adj[N];
vector<pair<pair<int, int>, int>> queries;
vector<pair<pair<int, ll>, int>> edges;

void dfs(int x, int par) {
    parent[x] = par;
    L[x] = ++discTime;

    for(int y : adj[x]) {
        if(y == par) continue;
        dfs(y, x);
    }

    R[x] = discTime;
}

void update(int node, int l, int r, int tl, int tr, ll val) {
    if(l > tr || r < tl) return;

    if(l >= tl && r <= tr) {
        seg_tree[node] = __gcd(seg_tree[node], val);
        return;
    }

    int m = (l + r) >> 1;
    update(node << 1, l, m, tl, tr, val);
    update(node << 1 | 1, m + 1, r, tl, tr, val);
}

ll query(int node, int l, int r, int x) {
    if(l > x || r < x) return 0;
    if(l == r) return seg_tree[node];

    int m = (l + r) >> 1;
    return __gcd(seg_tree[node], 
    __gcd(query(node << 1, l, m, x), 
    query(node << 1 | 1, m + 1, r, x)));
}

int main() {
    int testcases;cin >> testcases;
    for(int cases = 1;cases <= testcases;cases++) {
        int n, q;cin >> n >> q;
        edges.clear(), queries.clear();
        for(int i = 1;i <= n;i++) adj[i].clear();

        for(int i = 1;i < n;i++) {
            int x, y, load;ll cost;
            cin >> x >> y >> load >> cost;
            
            adj[x].push_back(y);
            adj[y].push_back(x);

            edges.push_back({{load, cost}, i});
            E[i] = {x, y};
        }

        discTime = 0;
        dfs(1, 0);

        for(int i = 1;i <= q;i++) {
            int c, w;
            cin >> c >> w;
            queries.push_back({{w, c}, i});
        }

        memset(seg_tree, 0, sizeof(seg_tree));

        int ptr = 0;
        sort(edges.begin(), edges.end());
        sort(queries.begin(), queries.end());

        for(auto quer : queries) {
            int w = quer.first.first, c = quer.first.second;
            int idx = quer.second;

            while(ptr < int(edges.size()) && w >= edges[ptr].first.first) {
                int edgeIdx = edges[ptr].second;
                ll cost = edges[ptr].first.second;

                int u = E[edgeIdx].first;
                int v = E[edgeIdx].second;

                if(parent[v] != u) swap(u, v);

                update(1, 1, n, L[v], R[v], cost);
                ptr++;
            }

            F[idx] = query(1, 1, n, L[c]);
        }

        cout << "Case #" << cases << ": ";
        for(int i = 1;i <= q;i++) cout << F[i] << " ";
        cout << endl;
    }

    return 0;
}