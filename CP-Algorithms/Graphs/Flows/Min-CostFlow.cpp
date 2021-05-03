#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int from, to, capacity, cost;
};

const int INF = 1e9;

vector<vector<int>> adj, capacity, cost;
void shortest_path(int n, int v0, vector<int> &d, vector<int> &p) {
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<int> q;
    q.push(v0);
    p.assign(n, -1);

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = true;
        for(int v : adj[u]) {
            if(capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if(!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

int min_cost_flow(int N, vector<Edge> edges, int K, int s, int t) {
    adj.resize(N);
    cost.assign(N, vector<int>(N, 0));
    capacity.assign(N, vector<int>(N, 0));

    for(Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }   

    int flow = 0;
    int cost = 0;
    vector<int> d, p;
    while(flow < K) {
        shortest_path(N, s, d, p);
        if(d[t] == INF) break;

        //find max flow on that path
        int f = K - flow;
        int cur = t;
        while(cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }

        //apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while(cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[p[cur]][cur] += f;
            cur = p[cur];
        }
    }
    
    if(flow < K) return -1;
    return cost;    
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    for(int i = 0;i < m;i++) {
        int a, b, cap, co;
        cin >> a >> b >> cap >> co;
        edges.push_back({a, b, cap, co});
    }

    cout << "Enter source and sink vertex : " << endl;
    int s, t;
    cin >> s >> t;
    cout << "Enter K : " << endl;
    int K;
    cin >> K;

    int ans = min_cost_flow(n, edges, K, s, t);
    
    cout << "The minimum cost from " << s << " to " << t << " is : " << ans << endl;
    return 0;
}
