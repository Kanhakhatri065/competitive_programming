#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> adj;

vector<int> pruferCode() {
    set<int> leafs;
    vector<int> degree(n);
    vector<bool> killed(n, false);

    for(int i = 0;i < n;i++) {
        degree[i] = int(adj[i].size());
        if(degree[i] == 1) leafs.insert(i);
    }

    vector<int> code(n - 2);
    for(int i = 0;i + 2 < n;i++) {
        int leaf = *leafs.begin();
        leafs.erase(leafs.begin());
        killed[leaf] = true;

        int v;
        for(int u : adj[leaf]) {
            if(!killed[u]) v = u;
        }

        code[i] = v;
        if(--degree[v] == 1) leafs.insert(v);
    }

    return code;
}

int main() {
    cin >> n;
    adj.resize(n);

    for(int i = 1;i < n;i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> prufer_code = pruferCode();

    cout << "Prufer code for the given tree is : " << endl;
    for(int v : prufer_code) cout << v << " ";
    cout << endl;

    return 0;
}
