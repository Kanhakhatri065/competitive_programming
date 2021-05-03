#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> pruferDecode(vector<int> code) {
    int n = int(code.size()) + 2;
    vector<int> degree(n, 1);

    for(int i : code) degree[i]++;

    int ptr = 0;
    while(degree[ptr] != 1) ptr++;
    int leaf = ptr;

    vector<pair<int, int>> edges;
    for(int v : code) {
        edges.emplace_back(leaf, v);
        if(--degree[v] == 1 && v < ptr) {
            leaf = v;
        } else {
            ptr++;
            while(degree[ptr] != 1) ptr++;
            leaf = ptr;
        }
    }

    edges.emplace_back(leaf, n - 1);
    return edges;
}

int main() {
    int n;cin >> n;

    vector<int> code(n);
    for(int i = 0;i < n;i++) cin >> code[i];

    vector<pair<int, int>> edges = pruferDecode(code);

    cout << "The edges are : " << endl;
    for(auto it : edges) cout << it.first << " " << it.second << endl;

    return 0;
}
