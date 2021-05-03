#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator <(Edge const& other) {
        return weight < other.weight;
    }
};

int n;
vector<Edge> edges;

void kruskal() {
    int cost = 0;
    vector<int> tree_id(n);
    vector<Edge> result;

    for(int i = 0;i < n;i++) {
        tree_id[i] = i;
    }

    sort(edges.begin(), edges.end());

    for(Edge e : edges) {
        if(tree_id[e.u] != tree_id[e.v]) {
            cost += e.weight;
            result.push_back(e);

            int old_id = tree_id[e.u], new_id = tree_id[e.v];
            for(int i = 0;i < n;i++) {
                if(tree_id[i] == old_id) {
                    tree_id[i] = new_id;
                }
            }
        }
    }

    cout << "Edges of MST are : " << endl;
    for(Edge x : result) {
        cout << x.u << " " << x.v << endl;
    }

    cout << "total_weight : " << cost << endl;
}

int main() {
    cin >> n;

    int m;
    cin >> m;

    for(int i = 0;i < m;i++) {
        int a, b, weight;
        cin >> a >> b >> weight;
        edges.push_back({a, b, weight});
    }

    kruskal();

    return 0;
}
