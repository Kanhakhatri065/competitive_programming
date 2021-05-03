#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<vector<int>> queries;
vector<int> ancestor;
vector<bool> visited;
int find_set(int v) {
    if(v == ancestor[v]) return v;
    return ancestor[v] = find_set(ancestor[v]);
}

void union_sets(int a, int b) {
    a = find_set(a), b = find_set(b);

    if(a != b) {
        ancestor[b] = a;
    }   
}

void dfs(int v) {
    visited[v] = true;
    ancestor[v] = v;
    for(int u : adj[v]) {
        if(!visited[u]) {
            dfs(u);
            union_sets(v, u);
            ancestor[find_set(v)] = v;
        }
    }

    for(int other_node : queries[v]) {
        if(visited[other_node]) {
            cout << "LCA of " << v << " and " << other_node;
            cout << " is " << ancestor[find_set(other_node)] << endl;
        }
    }
}

int main() {
    cin >> n;
    adj.resize(n);
    queries.resize(n);
    visited.assign(n, false);
    ancestor.resize(n);

    for(int i = 1;i < n;i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int q;
    cin >> q;
    for(int i = 0;i < q;i++) {
        int a, b;
        cin >> a >> b;
        queries[a].push_back(b);
        queries[b].push_back(a);
    }

    dfs(0);
}

