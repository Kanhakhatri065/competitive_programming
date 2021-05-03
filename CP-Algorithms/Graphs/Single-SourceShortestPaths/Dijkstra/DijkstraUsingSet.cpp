#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
vector<vector<pair<int, int>>> adj;
    vector<int> dest;
    vector<int> p;
    int n, m;
    void dijkstra(int s) {
        dest.assign(n, INF);
        p.assign(n, -1);

        dest[s] = 0;
        set<pair<int, int>> q;
        q.insert({0, s});
        while(!q.empty()) {
            int v = q.begin()->second;
        q.erase(q.begin());

        for(auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if(dest[v] + len < dest[to]) {
                q.erase({dest[to], to});
                dest[to] = dest[v] + len;
                p[to] = v;
                q.insert({dest[to], to});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    adj.resize(n);
    for(int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    dijkstra(0);
    for(int i = 0;i < n;i++) cout << dest[i] << " ";
    cout << endl;

    return 0;
}
