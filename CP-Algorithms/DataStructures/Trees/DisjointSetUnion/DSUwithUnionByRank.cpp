#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int par[N], rnk[N];

void make_set(int v) {
    par[v] = v;
    rnk[v] = 0;
}

int find_set(int v) {
    if(v == par[v]) return v;
    return par[v] = find_set(par[v]);
}

void union_sets(int a, int b) {
    a = find_set(a), b = find_set(b);
    if(a != b) {
        if(rnk[a] < rnk[b]) swap(a, b);
        par[b] = a;
        if(rnk[a] == rnk[b]) rnk[a]++;
    }
}

int main() {
    for(int i = 1; i<= 8;i++) make_set(i);

    union_sets(1, 2);
    union_sets(2, 3);
    union_sets(2, 4);
    union_sets(3, 6);
    union_sets(6, 8);
    union_sets(3, 5);
    union_sets(5, 7);

    for(int i = 1;i <= 8;i++) {
        cout << "Parent of " << i << " is : " << par[i] << " ";
        cout << "depth of the node is : " << rnk[i] << endl;
    }

    return 0;
}
