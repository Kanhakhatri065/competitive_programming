#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int parent[N];

void make_set(int v) {parent[v] = v;}

int find_set(int v) {
	if(v == parent[v]) return v;
	return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b) {
	a = find_set(a);
	b = find_set(b);

	if(a != b) {
		if(rand() % 2) {
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

	for(int i = 1;i <= 5;i++) cout << i << " p : " << parent[i] << endl;
	return 0;
}
