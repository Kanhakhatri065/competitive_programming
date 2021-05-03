#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int parent[N];

void make_set(int v) {
	parent[v] = v;
}

int find_set(int v) {
	if(v == parent[v]) return v;
	return find_set(parent[v]);
}

void union_set(int a, int b) {
	a = find_set(a);
	b = find_set(b);

	if(a != b) parent[b] = a;
}

int main() {
	for(int i = 1;i <= 5;i++) make_set(i);

	union_set(1, 2);
	union_set(3, 4);
	union_set(1, 3);

	for(int i = 1;i <= 5;i++) cout << parent[i] << " ";
	cout << endl;

	return 0;
}
