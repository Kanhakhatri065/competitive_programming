#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
int n;

vector<bool> used;
vector<int> d, p;

void bfs(int s) {
	used.assign(n, false);
	d.resize(n);
	p.resize(n);

	queue<int> q;
	q.push(s);
	used[s] = true;
	p[s] = -1;
	
	cout << "BFS : ";
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		cout << v << " ";
		for(int u : adj[v]) {
			if(!used[u]) {
				used[u] = true;
				q.push(u);
				d[u] = d[v] + 1;
				p[u] = v;
			}
		}
	}

	cout << endl;
}

int main() {
	scanf("%d", &n);
	adj.resize(n);
	for(int i = 1;i < n;i++) {
		int u, v;
		scanf("%d%d", &u, &v);

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int source;
	printf("Enter source : \n");
	scanf("%d", &source);

	bfs(source);	

	return 0;
}
