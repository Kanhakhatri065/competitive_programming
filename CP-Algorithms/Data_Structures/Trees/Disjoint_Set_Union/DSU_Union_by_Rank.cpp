#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int parent[N];
int rnk[N];

void make_set(int v) {
	parent[v] = v;
	rnk[v] = 0;
}

int find_set(int v) {
	if(v == parent[v]) return v;
	return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b) {
	a = find_set(a);
	b = find_set(b);

	if(b != a) {
		if(rnk[a] < rnk[b]) swap(a, b);

		parent[b] = a;
		if(rnk[a] == rnk[b]) rnk[a]++;
	}
}

int main() {
	for(int i = 1;i <= 5;i++) make_set(i);

	union_set(1, 2);
	union_set(2, 3);
	union_set(2, 4);
	union_set(3, 5);

	for(int i = 1;i <= 5;i++) cout << "parent of " << i << " is : " << parent[i] << " and rank is : " << rnk[i] << endl;
	return 0;
}
