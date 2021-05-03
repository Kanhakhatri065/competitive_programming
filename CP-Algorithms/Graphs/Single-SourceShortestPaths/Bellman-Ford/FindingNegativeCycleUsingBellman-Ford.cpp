#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int a, b, cost;
};

int n, m, v;
vector<Edge> edges;
const int INF = 1e9;

void solve() {
    vector<int> d(n, INF);
    d[v] = 0;
    vector<int> p(n, -1);
    int x;
    for(int i = 0;i < n;i++) {
        x = -1;
        for(int j = 0;j < m;j++) {
            if(d[edges[j].a] < INF) {
                if(d[edges[j].b] > d[edges[j].a] + edges[j].cost) {
                    d[edges[j].b] = d[edges[j].a] + edges[j].cost;
                    p[edges[j].b] = edges[j].a;
                    x = edges[j].b;
                }
            }
        }
    }

    if(x == -1) {
        cout << "No negative cycle found : " << endl;
    } else {
        int y = x;
        for(int i = 0;i < n;i++) y = p[y];

        vector<int> path;
        for(int cur = y;;cur = p[cur]) {
            path.push_back(cur);
            if(cur == y && int(path.size()) > 1) {
                break;
            }
        }

        reverse(path.begin(), path.end());
        cout << "Negative cycle : ";
        for(int u : path) cout << u << " ";
        cout << endl;
    }
}

int main() {
    cin >> n >> m;

    for(int i = 0;i < m;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    cout << "Source vertex : " << endl;
    cin >> v;

    solve();
    return 0;
}
