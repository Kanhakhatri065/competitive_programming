#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;

bool is_bipartite() {
    vector<int> side(n, -1);
    bool flag = true;
    queue<int> q;
    for(int i = 0;i < n;i++) {
        if(side[i] == -1) {
            q.push(i);
            side[i] = 0;
            while(!q.empty()) {
                int v = q.front();
                q.pop();
                for(int u : adj[v]) {
                    if(side[u] == -1) {
                        side[u] = side[v] ^ 1;
                        q.push(u);
                    } else {
                        flag &= (side[u] != side[v]);
                    }
                }
            }
        }
    }

    return flag;
}

int main() {
    cin >> n;
    adj.resize(n);
    int m;
    cin >> m;
    for(int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool ans = is_bipartite();
    cout << "Bipartite check : " << (ans ? "Yes" : "No") << endl;
    return 0;
}
