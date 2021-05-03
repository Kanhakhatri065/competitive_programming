#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int parent[N], siz[N];

void make_set(int v) {
	parent[v] = v;
	siz[v] = 1;
}

int find_set(int v) {
	if(v == parent[v]) return v;
	return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b) {
	a = find_set(a);
	b = find_set(b);

	if(a != b) {
		if(siz[a] < siz[b]) swap(a, b);
		parent[b] = a;
		siz[a] += siz[b];
	}
}

int main() {
	for(int i = 1;i <= 5;i++) make_set(i);

	union_set(1, 2);
	union_set(2, 3);
	union_set(2, 4);
	union_set(1, 5);

	for(int i = 1;i <= 5;i++) {
		cout << "parent of " << i << " is : " << parent[i] << " and size is : " << siz[i] << endl;
	}

	return 0;
}
