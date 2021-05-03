#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n, m;
vector<vector<int>> dist;

bool solve() {
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            for(int t = 0;t < n;t++) {
                if(dist[i][t] + dist[t][j] < dist[i][j]) {
                    dist[i][j] = dist[i][t] + dist[t][j];
                }
            }
        }
    }

    for(int i = 0;i < n;i++) if(dist[i][i] < 0) return true;
    return false;
}

int main() {
   cin >> n >> m;
   dist.assign(n, vector<int>(n, INF));

   for(int i = 0;i < n;i++) dist[i][i] = 0;
   for(int i = 0;i < m;i++) {
       int a, b, cost;
       cin >> a >> b >> cost;
       dist[a][b] = min(dist[a][b], cost);
   }

   if(solve()) {
       cout << "Contains a negative cycle" << endl;
   } else {
       cout << "No negative cycle found" << endl;
   }

   return 0;
}
