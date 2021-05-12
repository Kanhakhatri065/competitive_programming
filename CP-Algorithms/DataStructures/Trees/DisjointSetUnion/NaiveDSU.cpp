#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int par[N];

void make_set(int v) {
    par[v] = v;
}

int find_set(int v) {
    if(v == par[v]) return v;
    return find_set(par[v]);
}

void union_sets(int a, int b) {
    a = find_set(a), b = find_set(b);
    if(a != b) {
        par[b] = a;
    }
}

int main() {
    for(int i = 1;i <= 5;i++) make_set(i);

    union_sets(2, 3);
    union_sets(3, 5);
    union_sets(2, 4);

    for(int i = 1;i <= 5;i++) {
        cout << "Leader of " << i << " is : " << find_set(i) << endl;
    }

    return 0;
}
