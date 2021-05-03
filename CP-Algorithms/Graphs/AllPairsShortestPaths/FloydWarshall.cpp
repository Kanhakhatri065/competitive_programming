#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m;
vector<vector<pair<int, int>>> adj;

vector<vector<int>> floydWarshall() {
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    for(int i = 1;i <= n;i++) dist[i][i] = 0;

    for(int i = 1;i <= n;i++) {
        for(auto it : adj[i]) {
            dist[i][it.first] = min(dist[i][it.first], it.second);
        }
    }

    for(int k = 1;k <= n;k++) {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    return dist;
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    for(int i = 0;i < m;i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    vector<vector<int>> dist = floydWarshall();
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(i != j) {
                if(dist[i][j] == INF) {
                    cout << "Path b/w " << i << " and " << j << " does not exist." << endl;
                } else {
                    cout << "Cost to reach from " << i << " to " << j << " is : " << dist[i][j] << endl;
                }
            }
        }
    }
    
    return 0;
}
