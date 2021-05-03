#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> adj;

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for(int to : adj[v]) {
        if(to == p) continue;

        if(visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(low[to] > tin[v]) {
                cout << "Bridge " << to << " to " << v << endl;
            }
        }
    }
}

void find_edges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);

    for(int i = 0;i < n;i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    cin >> n;

    adj.resize(n);
    
    int m;
    cin >> m;
    for(int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    find_edges();

    return 0;
}
