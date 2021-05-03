#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct edge {
    int a, b, cost;
    edge() {}
    edge(int _a, int _b, int _cost) {
        a = _a;
        b = _b;
        cost = _cost;
    }
};

int n, m, v;
vector<edge> e;
vector<int> d;
void solve() {
    d.assign(n, INF);
    d[v] = 0;

    for(int i = 0;i < n - 1;i++) {
        for(int j = 0;j < m;j++) {
            if(d[e[j].a] < INF) {
                d[e[j].b] = min(d[e[j].b], d[e[j].a] + e[j].cost);
            }
        }
    }

    for(int i = 0;i < n;i++) cout << d[i] << " ";
    cout << endl;
}

int main() {
    cin >> n >> m;
    v = 0;
    for(int i = 0;i < m;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        e.push_back(edge(a, b, c));
    }

    solve();
    return 0;
}
