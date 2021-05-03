#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> par;
int cycle_start, cycle_end;

bool dfs(int v, int p) {
    visited[v] = true;
    for(int u : adj[v]) {
        if(u == p) continue;
        if(visited[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        
        par[u] = v;
        if(dfs(u, par[u])) return true;
    }

    return false;
}

void find_cycle() {
    visited.assign(n, false);
    par.assign(n, -1);
    cycle_start = -1;

    for(int v = 0;v < n;v++) {
        if(!visited[v] && dfs(v, par[v])) break;
    }

    if(cycle_start == -1) {
        cout << "Acyclic" << endl;
    } else {
        vector<int> cycle;

        cycle.push_back(cycle_start);
        for(int v = cycle_end;v != cycle_start;v = par[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(cycle_start);

        reverse(cycle.begin(), cycle.end());
        
        cout << "Cycle found : ";
        for(int v : cycle) cout << v << " ";
        cout << endl;
    }
}

int main() {
    int m;
    cin >> n >> m;
    adj.resize(n);
    for(int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;

        adj[b].push_back(a);
        adj[a].push_back(b);
    }

    find_cycle();

    return 0;
}
