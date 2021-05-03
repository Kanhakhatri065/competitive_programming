#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
vector<vector<pair<int, int>>> adj;
vector<int> d;
int n, m, s;
void solve() {
    d.assign(n, INF);
    d[s] = 0;
    deque<int> q;
    q.push_front(s);

    while(!q.empty()) {
        int v = q.front();
        q.pop_front();
        for(auto edge : adj[v]) {
            int u = edge.first;
            int w = edge.second;

            if(d[v] + w < d[u]) {
                d[u] = d[v] + w;
                if(w == 1) {
                    q.push_back(u);
                } else {
                    q.push_front(u);
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
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    cout << "Source vertex : " << endl;
    cin >> s;
    
    solve();

    for(int i = 0;i < n;i++) {
        cout << "i : " << i << " d[i] : " << d[i] << endl;
    }
    
    return 0;
}
