#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct edge {
    int s, e, w, id;
    bool operator <(const struct edge& other) {return w < other.w;}
};

typedef struct edge Edge;

const int N = 2e5 + 5;
ll res = 0, ans = 1e18;
int n, m, a, b, w, id, l = 21;
vector<Edge> edges;
vector<int> h(N, 0), parent(N, -1), sz(N, 0), present(N, 0);
vector<vector<pair<int, int>>> adj(N), dp(N, vector<pair<int, int>> (l));
vector<vector<int>> up(N, vector<int>(l, -1));

int find_set(int v) {
    if(v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

bool unite_set(int a, int b) {
    a = find_set(a), b = find_set(b);

    if(a != b) {
        if(sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        if(sz[a] == sz[b]) sz[a]++;
        return true;
    }

    return false;
}

pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
    vector<int> v = {a.first, a.second, b.first, b.second};
    int topTwo = -3, topOne = -2;
    for(int c : v) {
        if(c > topOne) {
            topTwo = topOne;
            topOne = c;
        } else if(c > topTwo && c < topOne) {
            topTwo = c;
        }
    }

    return {topOne, topTwo};
}

void dfs(int u, int par, int d) {
    h[u] = 1 + h[par];
    up[u][0] = par;
    dp[u][0] = {d, -1};
    for(auto v : adj[u]) {
        if(v.first != par) {
            dfs(v.first, u, v.second);
        }
    }
}

pair<int, int> lca(int u, int v) {
    pair<int, int> an = {-2, -3};
    if(h[u] < h[v]) swap(u, v);

    for(int i = l - 1;i >= 0;i--) {
        if(h[u] - h[v] >= (1 << i)) {
            an = combine(an, dp[u][i]);
            u = up[u][i];
        }
    }

    if(u == v) {
        return an;
    }

    for(int i = l - 1;i >= 0;i--) {
        if(up[u][i] != -1 && up[v][i] != -1 && up[u][i] != up[v][i]) {
            an = combine(an, combine(dp[u][i], dp[v][i]));
            u = up[u][i];
            v = up[v][i];
        }
    }

    an = combine(an, combine(dp[u][0], dp[v][0]));
    return an;
}

int main() {
    cin >> n >> m;
    
    for(int i = 1;i <= n;i++) {
        parent[i] = i;
        sz[i] = i;
    }

    for(int i = 1;i <= m;i++) {
        cin >> a >> b >> w;
        edges.push_back({a, b, w, i - 1});
    }

    sort(edges.begin(), edges.end());

    for(int i = 0;i < m;i++) {
        a = edges[i].s;
        b = edges[i].e;
        w = edges[i].w;
        id = edges[i].id;
        if(unite_set(a, b)) {
            adj[a].emplace_back(b, w);
            adj[b].emplace_back(a, w);
            present[id] = 1;
            res += w;
        }   
    }

    dfs(1, 0, 0);

    for(int i = 1;i <= l - 1;i++) {
        for(int j = 1;j <= n;j++) {
            if(up[j][i - 1] != -1) {
                int v = up[j][i - 1];
                up[j][i] = up[v][i - 1];
                dp[j][i] = combine(dp[j][i - 1], dp[v][i - 1]);
            }
        }
    }

    for(int i = 0;i < m;i++) {
        id = edges[i].id;
        w = edges[i].w;

        if(!present[id]) {
            auto rem = lca(edges[i].s, edges[i].e);
            if(rem.first != w) {
                ans = min(ans, res + w - rem.first);
            } else if(rem.second != -1) {
                ans = min(ans, res + w - rem.second);
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}