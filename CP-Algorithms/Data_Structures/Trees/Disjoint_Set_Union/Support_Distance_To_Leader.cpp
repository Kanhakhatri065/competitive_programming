#include <bits/stdc++.h>

using namespace std;

const int N = 105;

pair<int, int> parent[N];
int rnk[N];

void make_set(int v) {
	parent[v] = make_pair(v, 0);
	rnk[v] = 0;
}

pair<int, int> find_set(int v) {
	if(v != parent[v].first) {
		int len = parent[v].second;
		parent[v] = find_set(parent[v].first);
		parent[v].second += len;
	}

	return parent[v];
}

void union_sets(int a, int b) {
	a = find_set(a).first;
	b = find_set(b).first;

	if(a != b) {
		if(rnk[a] < rnk[b]) swap(a, b);
		parent[b] = make_pair(a, 1);
		if(rnk[a] == rnk[b]) rnk[a]++;
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	for(int i = 0;i < n;i++) {
		make_set(i);
	}

	for(int i = 0;i < m;i++) {
		int l, r;
		cin >> l >> r;

		union_sets(l, r);
	}

	for(int i = 0;i < n;i++) {
		cout << "i : " << i << " parent : " << parent[i].first << " distance : " << parent[i].second << endl;
	}
	
	return 0;
}

