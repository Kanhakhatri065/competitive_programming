#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for(int u : adj[v]) {
        if(!visited[u]) {
            dfs(u);
        }
    }

    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    ans.clear();
    for(int i = 0;i < n;i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }

    reverse(ans.begin(), ans.end());
    for(int x : ans) cout << x << " ";
    cout << endl;
}

int main() {
    cin >> n;
    adj.resize(n);
    int m;
    cin >> m;

    for(int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
    }

    topological_sort();

    return 0;
}
