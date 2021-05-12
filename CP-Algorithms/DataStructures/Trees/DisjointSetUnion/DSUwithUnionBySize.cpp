#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int par[N], siz[N];

void make_set(int v) {
    par[v] = v;
    siz[v] = 1;
}

int find_set(int v) {
    if(v == par[v]) return v;
    return par[v] = find_set(par[v]);
}

void union_sets(int a, int b) {
    a = find_set(a), b = find_set(b);

    if(a != b) {
        if(siz[a] < siz[b]) swap(a, b);
        par[b] = a;
        siz[a] += siz[b];
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
        cout << "Parent of " << i << "is : " << par[i] << " ";
        cout << "Size of the tree is : " << siz[i] << endl;
    }

    return 0;
}
