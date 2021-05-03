#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
int n;

vector<int> color;

vector<int> timer_in, timer_out;
int dfs_timer = 0;
vector<int> path;
void dfs(int v) {
	path.push_back(v);
	timer_in[v] = dfs_timer++;
	color[v] = 1;

	for(int u : adj[v]) {
		if(color[u] == 0) dfs(u);
	}

	color[v] = 2;
	timer_out[v] = dfs_timer++;
}

int main() {
	scanf("%d", &n);
	adj.resize(n);
	color.resize(n);
	timer_in.resize(n);
	timer_out.resize(n);

	for(int i = 1;i < n;i++) {
		int u, v;
		scanf("%d%d", &u, &v);

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cout << "Enter source vertex : " << endl;
	int source;
	cin >> source;

	dfs(source);
	
	cout << "path : ";
	for(int it : path) {
		cout << it << " ";
	}
	cout << endl;

	for(int i = 0;i < n;i++) {
		cout << "i : " << i << " timer_in : " << timer_in[i] << " timer_out : " << timer_out[i] << endl;
	}

	return 0;
}
