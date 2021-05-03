#include <bits/stdc++.h>

using namespace std;

const int N = 105;
vector<int> lst[N];
int parent[N];

void make_set(int v) {
	lst[v] = vector<int>(1, v);
	parent[v] = v;
}

int find_set(int v) {
	return parent[v];
}

void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);

	if(a != b) {
		if(int(lst[a].size()) < int(lst[b].size())) {
			swap(a, b);
		}

		while(!lst[b].empty()) {
			int v = lst[b].back();
			lst[b].pop_back();
			parent[v] = a;
			lst[a].push_back(v);
		}
	}
}

int main() {
	int n;
	cin >> n;

	for(int i = 0;i < n;i++) make_set(i);

	for(int i = 1;i < n;i++) {
		int u, v;
		cin >> u >> v;

		union_sets(u, v);
	}

	for(int i = 0;i < n;i++) {
		cout << i << " parent : " << parent[i] << endl;
	}

	return 0;
}
