#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int par[N];

void make_set(int v) {
    par[v] = v;
}

int find_set(int v) {
    if(v == par[v]) return v;
    return par[v] = find_set(par[v]);
}

void union_sets(int a, int b) {
    a = find_set(a), b = find_set(b);
    if(a != b) {
        par[b] = a;
    }
}

int main() {
    for(int i = 1;i <= 8;i++) make_set(i);

    par[2] = 1;
    par[3] = 2;
    par[4] = 2;
    par[5] = 3;
    par[6] = 3;
    par[7] = 5;
    par[8] = 6;
    
    cout << "Showing parents before find_set operation : " << endl;
    for(int i = 1;i <= 8;i++) {
        cout << "Parent of " << i << " is : " << par[i] << endl;
    }

    int x = find_set(7);
    cout << "Showing parents after find_set operation : " << endl;
    for(int i = 1;i <= 8;i++) {
        cout << "Parent of " << i << " is : " << par[i] << endl;
    }

    return 0;
}
