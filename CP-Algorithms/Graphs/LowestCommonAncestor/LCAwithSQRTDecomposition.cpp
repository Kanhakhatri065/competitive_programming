#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;

int block_sz; // block size = sqrt(height)
int max_height;
int depth[MAX]; //depth of each node
int par[MAX]; // parent of each node
int jump_par[MAX]; // stores first ancestor in previous block
vector<int> adj[MAX];

void find_height(int u, int p, int h = 0) {
    max_height = max(max_height, h + 1);
    
    for(int v : adj[u]) {
        if(v != p) {
            find_height(v, u, h + 1);
        }
    }
}

int lcaNaive(int u, int v) {
    if(u == v) return u;
    if(depth[u] > depth[v]) swap(u, v);
    v = par[v];
    return lcaNaive(u, v);
}

void dfs(int cur, int p) {
    if(cur == 0) depth[cur] = 0;
    else  depth[cur] = depth[p] + 1;
    par[cur] = p;

    if(depth[cur] % block_sz == 0) {
        jump_par[cur] = par[cur];
    } else {
        jump_par[cur] = jump_par[p];
    }

    for(int u : adj[cur]) {
        if(u != p) {
            dfs(u, cur);
        }
    }
}

int lcaSQRT(int u, int v) {
    while(jump_par[u] != jump_par[v]) {
        if(depth[u] > depth[v]) swap(u, v);
        v = jump_par[v];
    }

    return lcaNaive(u, v);
}

void preprocess() {
    max_height = 0;
    find_height(0, -1);
    block_sz = sqrt(max_height);

    dfs(0, -1);
}

int main() {
    int n;
    cin >> n;

    for(int i = 1;i < n;i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    preprocess();

    int q;
    cin >> q;

    while(q--) {
        int a, b;
        cin >> a >> b;

        cout << "LCA of " << a << " and " << b << " is : " << lcaSQRT(a, b) << endl;
    }

    return 0;
}
