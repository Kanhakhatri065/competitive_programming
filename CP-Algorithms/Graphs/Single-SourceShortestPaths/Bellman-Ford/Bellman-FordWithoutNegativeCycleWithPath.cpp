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

vector<edge> e;
vector<int> d, p;
int n, m, v, t;

void solve() {
    d.assign(n, INF);
    p.assign(n, -1);
    d[v] = 0;

    for(;;) {
        bool flag = false;
        for(int j = 0;j < m;j++) {
            if(d[e[j].a] < INF) {
                if(d[e[j].b] > d[e[j].a] + e[j].cost) {
                    d[e[j].b] = d[e[j].a] + e[j].cost;
                    p[e[j].b] = e[j].a;
                    flag = true;
                }
            }
        }

        if(!flag) break;
    }

    if(d[t] == INF) {
        cout << "No path from " << v << " to " << t << endl;
    } else {
        vector<int> path;
        for(int cur = t;cur != -1;cur = p[cur]) {
            path.push_back(cur);
        }

        reverse(path.begin(), path.end());

        cout << "Path from " << v << " to " << t << endl;
        for(int i = 0;i < int(path.size());i++) cout << path[i] << " ";
        cout << endl;
    }
}

int main() {
    cin >> n >> m;

    for(int i = 0;i < m;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        e.push_back(edge(a, b, c));
    }

    cout << "Source vertex : " << endl;
    cin >> v;
    cout << "Destination vertex : " << endl;
    cin >> t;
    
    solve();

    return 0;
}
