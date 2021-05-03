#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> adj;

vector<bool> visited;
vector<int> tin, low;
int timer;

set<int> articulation_points;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;

    int children = 0;
    for(int to : adj[v]) {
        if(to == p) continue;

        if(visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(low[to] >= tin[v] && p != -1) {
                articulation_points.insert(v);
            }
            children++;
        }
    }

    if(p == -1 && children > 1) {
        articulation_points.insert(v);
    }
}

void find_cutpoints() {
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
    cout << "No of vertices : " << endl;
    cin >> n;
    adj.resize(n);

    cout << "No. of edges : " << endl;
    int m;
    cin >> m;

    for(int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    find_cutpoints();

    cout << "No. of articulation_points : " << int(articulation_points.size()) << endl;
    for(int v : articulation_points) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
