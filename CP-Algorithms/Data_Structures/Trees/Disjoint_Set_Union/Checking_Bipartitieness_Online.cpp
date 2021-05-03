#include <bits/stdc++.h>

using namespace std;

const int N = 105;

pair<int, int> parent[N];
int rnk[N];
bool bipartite[N];

void make_set(int v) {
	parent[v] = make_pair(v, 0);
	rnk[v] = 0;
	bipartite[v] = true;
}

pair<int, int> find_set(int v) {
	if(v != parent[v].first) {
		int parity = parent[v].second;
		parent[v] = find_set(parent[v].first);
		parent[v].second ^= parity;
	}

	return parent[v];
}

void add_edge(int a, int b) {
	pair<int, int> pa = find_set(a);
	a = pa.first;
	int x = pa.second;

	pair<int, int> pb = find_set(b);
	b = pb.first;
	int y = pb.second;

	if(a == b) {
		if(x == y) bipartite[a] = false;
	} else {
		if(rnk[a] < rnk[b]) swap(a, b);
		parent[b] = make_pair(a, x ^ y ^ 1);
		bipartite[a] &= bipartite[b];

		if(rnk[a] == rnk[b]) rnk[a]++;
	}
}

bool is_bipartite(int v) {
	return bipartite[find_set(v).first];
}

int main() {
	int n;
	cin >> n;

	for(int i = 1;i <= n;i++) make_set(i);

	for(int i = 1;i < n;i++) {
		int u, v;
		cin >> u >> v;

		add_edge(u, v);
	}

	for(int i = 1;i <= n;i++) {
		cout << i << " bipartite : " << bipartite[i] << endl;
	}

}
