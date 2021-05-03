#include <bits/stdc++.h>
using namespace std;

vector<int> par, rnk;
void make_set(int v) {
    par[v] = v;
    rnk[v] = 0;
}

int find_set(int v) {
    if(v == par[v]) return v;
    return par[v] = find_set(par[v]);
}

void union_sets(int a, int b) {
    a = find_set(a), b = find_set(b);
    
    if(a != b) {
        if(rnk[a] < rnk[b]) swap(a, b);
        par[b] = a;
        if(rnk[a] == rnk[b]) rnk[a]++;
    }
}

struct Edge {
    int u, v, weight;
    bool operator <(Edge const& other) {
        return weight < other.weight;
    }
};

int n;
vector<Edge> edges;

void KruskalWithDSU() {
    int cost = 0;
    vector<Edge> result;
    par.resize(n);
    rnk.resize(n);

    for(int i = 0;i < n;i++) make_set(i);

    sort(edges.begin(), edges.end());

    for(Edge e : edges) {
        if(find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }

    cout << "Edges of MST are : " << endl;
    for(Edge e : result) {
        cout << e.u << " " << e.v << endl;
    }

    cout << "Total Weight : " << cost << endl;
}

int main() {
    cin >> n;

    int m;
    cin >> m;

    for(int i = 0;i < m;i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({a, b, w});
    }

    KruskalWithDSU();

    return 0;
}