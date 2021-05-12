#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

pair<int,int> par[N];
int rnk[N];

void make_set(int v) {
    par[v] = make_pair(v, 0);
    rnk[v] = 0;
}

pair<int, int> find_set(int v) {
    if (v != par[v].first) {
        int len = par[v].second;
        par[v] = find_set(par[v].first);
        par[v].second += len;
    }
    return par[v];
}

void union_sets(int a, int b) {
    a = find_set(a).first;
    b = find_set(b).first;
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        par[b] = make_pair(a, 1);
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
}

int main() {
    int n = 8;
    for(int i = 1;i <= n;i++) make_set(i);

    union_sets(1, 2);
    union_sets(2, 3);
    union_sets(2, 4);
    union_sets(3, 5);
    union_sets(3, 6);
    union_sets(6, 8);
    union_sets(5, 7);

    for(int i = 1;i <= n;i++) {
        int v = i;
        cout << "Node : " << i << " representative : " << par[v].first << " distance : " << par[v].second << endl;
    }

    return 0;
}
