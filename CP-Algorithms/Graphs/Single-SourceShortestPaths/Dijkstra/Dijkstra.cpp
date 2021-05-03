#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> &d, vector<int> &p) {
    int n = int(adj.size());
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);
    d[s] = 0;
    for(int i = 0;i < n;i++) {
        int v = -1;
        for(int j = 0;j < n;j++) {
            if(!u[j] && (v == -1 ||  d[j] < d[v])) v = j;
        }

        if(d[v] == INF) break;

        u[v] = true;
        for(auto edge : adj[v]) {
           int to = edge.first;
           int len = edge.second;

           if(d[v] + len < d[to]) {
               d[to] = d[v] + len;
               p[to] = v;
           }
        }
    }
}

vector<int> restore_path(int s, int t, vector<int> const &p) {
    vector<int> path;
    for(int v = t;v != s;v = p[v]) path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
    return path;
}

int main() {
    cout << "No of vertices : " << endl;
    int n;cin >> n;

    cout << "No of edges : " << endl;
    int m;cin >> m;
    
    adj.resize(n);
    for(int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int s = 0;
    vector<int> d, p;
    dijkstra(s, d, p);

    vector<int> path = restore_path(0, 4, p);
    cout << "Path : ";
    for(int v : path) cout << v << " ";
    cout << endl;

    return 0;
}