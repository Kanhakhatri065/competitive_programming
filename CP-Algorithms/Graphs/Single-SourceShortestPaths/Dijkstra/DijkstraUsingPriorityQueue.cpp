#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

vector<vector<pair<int, int>>> adj;
vector<int> d;
vector<int> p;
int n, m;
void dijkstra(int s) {
    d.assign(n, INF);
    p.assign(n, -1);
    d[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, s);

    while(!pq.empty()) {
        auto [d_v, v] = pq.top();
        pq.pop();

        if(d_v != d[v]) continue;
        for(auto [to, len] : adj[v]) {
            if(d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                pq.emplace(d[to], to);
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
        adj[u].emplace_back(v, w);
    }

    dijkstra(0);
    for(int i = 0;i < n;i++) cout << d[i] << ' ';
    cout << endl;
    return 0;
}
