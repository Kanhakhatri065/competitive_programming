#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int par[N], idx[N];

void make_set(int v) {
    par[v] = v;
    idx[v] = rand();
}

int find_set(int v) {
    if(v == par[v]) return v;
    return par[v] = find_set(par[v]);
}

void union_sets(int a, int b) {
    a = find_set(a), b = find_set(b);

    if(a != b) {
        if(idx[a] < idx[b]) swap(a, b);
        par[b] = a;
    }
}

void union_set(int a, int b) {
    a = find_set(a), b = find_set(b);

    if(a != b) {
        if(rand() & 1) swap(a, b);
        par[b] = a;
    }
}

int main() {
    int n = 8;
    for(int i = 1;i <= n;i++) make_set(i);
    
    union_sets(1, 2);
    union_sets(2, 3);
    union_sets(3, 6);
    union_sets(6, 8);
    union_sets(3, 5);
    union_sets(5, 7);
    union_sets(2, 4);

    for(int i = 1;i <= 8;i++) {
        cout << "i : " << i << " par : " << par[i] << endl;
    }

    return 0;
}
