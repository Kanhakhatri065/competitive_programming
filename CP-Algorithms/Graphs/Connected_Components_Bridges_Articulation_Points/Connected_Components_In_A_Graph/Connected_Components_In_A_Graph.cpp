#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n;
vector<int> graph[N];
bool used[N];
vector<int> comp;

void dfs(int v) {
    used[v] = true;
    comp.push_back(v);
    for(int u : graph[v]) {
        if(!used[u]) dfs(u);
    }
}

void find_comps() {
    memset(used, false, sizeof(used));
    
    for(int i = 0;i < n;i++) {
        if(!used[i]) {
            comp.clear();
            dfs(i);

            cout << "Component : ";
            for(int j : comp) {
                cout << j << " ";
            }

            cout << endl;
        }
    }
}

int main() {
    cin >> n;

    for(int i = 1;i < n;i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    find_comps();

    return 0;
}
