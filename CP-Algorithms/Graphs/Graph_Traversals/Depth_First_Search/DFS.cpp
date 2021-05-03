#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int n;

void dfs(int v) {
	visited[v] = true;
	cout << v << " ";

	for(int u : adj[v]) {
		if(!visited[u]) dfs(u);
	}
}

int main() {
	scanf("%d", &n);
	adj.resize(n);
	visited.assign(n, false);

	for(int i = 1;i < n;i++) {
		int u, v;
		scanf("%d%d", &u, &v);

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cout << "DFS : ";
	dfs(0);
	cout << endl;
	return 0;
}
