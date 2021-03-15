#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> adj[N];
vector<int> p;

void dfs(int u) {
    while(!adj[u].empty()) {
        int v = adj[u].back();
        adj[u].pop_back();
        dfs(v);
    }

    p.push_back(u);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> in(n + 1), out(n + 1); 
    for(int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        out[u]++, in[v]++;
    }

    int a = 0, b= 0, c = 0, s1 = 0, s2 = 0;
    for(int i = 1;i <= n;i++) {
        if(in[i] == out[i]) c++;
        if(in[i] - out[i] == 1) b++, s2 = i;
        if(in[i] - out[i] == -1) a++, s1 = i;
    }

    if(s1 != 1 || s2 != n) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    if(!(c == n - 2 && a == 1 && b == 1)) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    dfs(1);
    if(int(p.size()) != m + 1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        reverse(p.begin(), p.end());
        for(int x : p) cout << x << " ";
        cout << endl;
    }

    return 0;
}
