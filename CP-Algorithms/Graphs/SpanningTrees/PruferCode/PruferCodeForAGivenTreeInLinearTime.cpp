#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> adj;
vector<int> par;

void dfs(int v) {
    for(int u : adj[v]) {
        if(u != par[v]) {
            par[u] = v;
            dfs(u);
        }
    }
}

vector<int> pruferCode() {
    par[n - 1] = -1;
    dfs(n - 1);

    int ptr = -1;
    vector<int> degree(n);
    for(int i = 0;i < n;i++) {
        degree[i] = int(adj[i].size());
        if(degree[i] == 1 && ptr == -1) {
            ptr = i;
        }
    }

    vector<int> code(n - 2);
    int leaf = ptr;
    for(int i = 0;i + 2 < n;i++) {
        int next = par[leaf];
        code[i] = next;
        if(--degree[next] == 1 && next < ptr) {
            leaf = next;
        } else {
            ptr++;
            while(degree[ptr] != 1) ptr++;
            leaf = ptr;
        }
    }

    return code;
}

int main() {
    cin >> n;
    adj.resize(n);
    par.resize(n);

    for(int i = 1;i < n;i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> prufer_code = pruferCode();

    cout << "Prufer code for given tree is : " << endl;
    for(int v : prufer_code) cout << v << " ";
    cout << endl;

    return 0;
}
