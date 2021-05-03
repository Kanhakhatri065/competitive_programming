#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n, m;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while(!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for(int next : adj[cur]) {
            if(parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if(next == t) {
                    return new_flow;
                }

                q.push({next, new_flow});
            }
        }
    }
    
    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;
    while((new_flow = bfs(s, t, parent)) > 0) {
        flow += new_flow;
        int cur = t;
        while(cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main() {
    cin >> n >> m;

    adj.resize(n);
    capacity.assign(n, vector<int>(n, 0));

    for(int i = 0;i < m;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(b);
        capacity[a][b] = c;
    }

    cout << "Source and sink vertex : " << endl;
    int s, t;
    cin >> s >> t;

    int ans = maxflow(s, t);
    cout << "Max flow in the graph is : " << ans << endl;

    return 0;
}
