#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

pair<int, int> par[N];
int rnk[N];
bool bipartite[N];

void make_set(int v) {
    par[v] = make_pair(v, 0);
    rnk[v] = 0;
    bipartite[v] = true;
}

pair<int, int> find_set(int v) {
    if (v != par[v].first) {
        int parity = par[v].second;
        par[v] = find_set(par[v].first);
        par[v].second ^= parity;
    }
    return par[v];
}

void add_edge(int a, int b) {
    pair<int, int> pa = find_set(a);
    a = pa.first;
    int x = pa.second;

    pair<int, int> pb = find_set(b);
    b = pb.first;
    int y = pb.second;

    if (a == b) {
        if (x == y)
            bipartite[a] = false;
    } else {
        if (rnk[a] < rnk[b])
            swap (a, b);
        par[b] = make_pair(a, x^y^1);
        bipartite[a] &= bipartite[b];
        if (rnk[a] == rnk[b])
            ++rnk[a];
    }
}

bool isbipartite(int v) {
    return bipartite[find_set(v).first];
}

int main() {
    int n = 8;
    for(int i = 1;i <= n;i++) make_set(i);
    
    cout << "No of unions : " << endl;
    int m;cin >> m;
    for(int i = 0;i < m;i++) {
        cout << "Enter vertices : " << endl;
        int x, y;cin >> x >> y;
        add_edge(x, y);
        cout << "Is the component bipartite : " << isbipartite(x) << endl;
    }

    return 0;
}
