#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int parent[N];
int idx[N];

void make_set(int v) {
	parent[v] = v;
	idx[v] = rand();
}

int find_set(int v) {
	if(v == parent[v]) return v;
	return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b) {
	a = find_set(a);
	b = find_set(b);

	if(a != b) {
		if(idx[a] < idx[b]) {
			swap(a, b);
		}
		parent[b] = a;
	}
}

int main() {
	for(int i = 1;i <= 5;i++) make_set(i);

	union_set(1, 2);
	union_set(1, 3);
	union_set(2, 4);
	union_set(2, 5);

	for(int i = 1;i <= 5;i++) cout << i << " parent[i] : " << parent[i] << endl;
	return 0;
}
