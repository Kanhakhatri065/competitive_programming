#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g, gr;
vector<bool> used;
vector<int> order, component;

void dfs1(int v) {
    used[v] = true;
    for(int u : g[v]) {
        if(!used[u]) {
            dfs1(u);
        }
    }

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for(int u : gr[v]) {
        if(!used[u]) {
            dfs2(u);
        }
    }
}

int main() {
    cout << "No. of vertices : " << endl;
    int n;
    cin >> n;

    cout << "No. of edges : " << endl;
    int m;
    cin >> m;

    g.resize(n);
    gr.resize(n);
    used.assign(n, false);

    for(int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        gr[b].push_back(a);
    }

    for(int i = 0;i < n;i++) {
        if(!used[i]) {
            dfs1(i);
        }
    }

    used.assign(n, false);
    for(int i = 0;i < n;i++) {
        int v = order[n - i - 1];
        if(!used[v]) {
            dfs2(v);

            cout << "Strongly Connected Component : ";
            for(int x : component) {
                cout << x << " ";
            }
            cout << endl;

            component.clear();
        }
    }

    return 0;
}
