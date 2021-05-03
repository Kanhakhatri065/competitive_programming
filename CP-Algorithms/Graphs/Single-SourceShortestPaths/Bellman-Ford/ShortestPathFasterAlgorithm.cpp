#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
vector<vector<pair<int, int>>> adj;
int n, m;
bool spfa(int s, vector<int> &d) {
    d.assign(n, INF);
    vector<int> cnt(n, 0);
    vector<bool> inqueue(n, false);
    queue<int> q;

    d[s] = 0;
    q.push(s);
    inqueue[s] = true;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        inqueue[v] = false;

        for(auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if(d[v] + len < d[to]) {
                d[to] = d[v] + len;
                if(!inqueue[to]) {
                    q.push(to);
                    inqueue[to] = true;
                    cnt[to]++;
                    if(cnt[to] > n) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    cin >> n >> m;
    adj.resize(n);
    for(int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> d;
    cout << "Source vertex : " << endl;
    int s;cin >> s;

    if(spfa(s, d)) {
        for(int i = 0;i < n;i++) cout << d[i] << ' ';
        cout << endl;
    } else {
        cout << "There is a negative cycle in this graph." << endl;
    }
    return 0;
}
