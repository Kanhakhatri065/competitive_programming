#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int a, b, cost;
};

int n, m;
vector<Edge> edges;
const int INF = 1e9;

void solve() {
    vector<int> d(n);
    vector<int> p(n, -1);

    int x;
    for(int i = 0;i < n;i++) {
        x = -1;
        for(auto e : edges) {
            if(d[e.a] + e.cost < d[e.b]) {
                d[e.b] = d[e.a] + e.cost;
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if(x == -1) {
        cout << "No negative cycle found" << endl;
    } else {
        for(int i = 0;i < n;i++) {
            x = p[x];
        }

        vector<int> cycle;
        for(int v = x;;v = p[v]) {
            cycle.push_back(v);
            if(v == x && cycle.size() > 1) break;
        }

        reverse(cycle.begin(), cycle.end());
        cout << "Negative cycle : ";
        for(int v : cycle) cout << v << " ";
        cout << endl;
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0;i < m;i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edges.push_back({a, b, cost});
    }

    solve();
    return 0;
}
