#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<pair<int, int>> edges;

vector<int> tin, low;
int bridge_cnt;
string orient;
vector<bool> edges_used;

void find_bridges(int v) {
    static int time = 0;
    low[v] = tin[v] = time++;

    for(auto p : adj[v]) {
        if(edges_used[p.second]) continue;
        edges_used[p.second] = true;

        orient[p.second] = v == edges[p.second].first ? '>' : '<';

        int nv = p.first;
        if(tin[nv] == -1) { // if nv is not visited
            find_bridges(nv);
            low[v] = min(low[v], low[nv]);
            if(low[nv] > tin[v]) {
                // a bridge between v and nv
                bridge_cnt++;
            }
        } else {
            low[v] = min(low[v], low[nv]);
        }
    }
}

int main() {
    int n;
    cout << "No. of vertices : " << endl;
    cin >> n;

    int m;
    cout << "No. of edges : " << endl;
    cin >> m;

    adj.resize(n);
    tin.resize(n, -1);
    low.resize(n, -1);
    orient.resize(m);
    edges.resize(m);
    edges_used.resize(m);
    for(int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
        edges[i] = {a, b};
    }
    
    bridge_cnt = 0;
    int comp_cnt = 0;
    for(int v = 0;v < n;v++) {
        if(tin[v] == -1) {
            comp_cnt++;
            find_bridges(v);
        }
    }

    cout << "Minimum no. of SCC : " << (comp_cnt + bridge_cnt) << endl;
    cout << "Orientation of edges : " << orient << endl;

}
