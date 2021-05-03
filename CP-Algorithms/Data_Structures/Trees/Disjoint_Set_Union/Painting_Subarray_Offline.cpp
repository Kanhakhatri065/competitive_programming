#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int ans[N], parent[N];

void make_set(int v) {
	parent[v] = v;
	ans[v] = 0;
}

int find_set(int v) {
	if(v == parent[v]) return v;
	return parent[v] = find_set(parent[v]);
}

struct Query {
	int l, r, c;
};

Query queries[N];

int main() {
	int n, m;
	cin >> n >> m;

	for(int i = 0;i < m;i++) {
		int l, r, c;
		cin >> l >> r >> c;

		queries[i].l = l;
		queries[i].r = r;
		queries[i].c = c;
	}

	for(int i = 0;i < n;i++) {
		make_set(i);
	}

	for(int i = m - 1;i >= 0;i--) {
		int l = queries[i].l, r = queries[i].r, c = queries[i].c;
		
		for(int v = find_set(l);v <= r;v = find_set(v)) {
			ans[v] = c;
			parent[v] = v + 1;
		}
	}

	for(int i = 0;i < n;i++) cout << ans[i] << " ";
	cout << endl;

	return 0;
}
