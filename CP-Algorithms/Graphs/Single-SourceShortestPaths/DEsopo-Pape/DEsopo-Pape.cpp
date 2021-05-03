#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int to, w;
};

vector<vector<Edge>> adj;
int n, m;
const int INF = 1e9;
vector<int> d, p;
void shortest_path(int v0) {
    d.assign(n, INF);
    d[v0] = 0;
    vector<int> m(n, 2);
    deque<int> q;
    q.push_back(v0);
    p.assign(n, -1);

    while(!q.empty()) {
        int u = q.front();
        q.pop_front();
        m[u] = 0;
        for(Edge e : adj[u]) {
            if(d[e.to] > d[u] + e.w) {
                d[e.to] = d[u] + e.w;
                p[e.to] = u;

                if(m[e.to] == 2) {
                    m[e.to] = 1;
                    q.push_back(e.to);
                } else if(m[e.to] == 0) {
                    m[e.to] = 1;
                    q.push_back(e.to);
                }
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

    cout << "Source vertex : " << endl;
    int v0;
    cin >> v0;

    shortest_path(v0);
    for(int i = 0;i < n;i++) cout << d[i] << " ";
    cout << endl;

    return 0;
}
