#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> lst[N];
int par[N];

void make_set(int v) {
    lst[v] = vector<int>(1, v);
    par[v] = v;
}

int find_set(int v) {
    return par[v];
}

void union_sets(int a, int b) {
    a = find_set(a), b = find_set(b);
    if(a != b) {
        if(int(lst[a].size()) < int(lst[b].size())) swap(a, b);
        while(!lst[b].empty()) {
            int v = lst[b].back();
            lst[b].pop_back();
            par[v] = a;
            lst[a].push_back(v);
        }
    }
}

int main() {
    int n = 8;
    for(int i = 1;i <= 8;i++) make_set(i);

    union_sets(1, 2);
    union_sets(2, 4);
    union_sets(2, 3);
    union_sets(4, 6);
    union_sets(6, 8);
    union_sets(3, 5);
    union_sets(5, 7);

    for(int i = 1;i <= n;i++) {
        cout << "Node : " << i << " parent : " << find_set(i) << endl;
    }

    return 0;
}
