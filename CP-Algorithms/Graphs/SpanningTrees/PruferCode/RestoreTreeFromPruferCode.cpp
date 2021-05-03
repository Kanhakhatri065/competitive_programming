#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> pruferDecode(vector<int> code) {
    int n = int(code.size()) + 2;
    vector<int> degree(n, 1);

    for(int i : code) degree[i]++;
    
    set<int> leaves;
    for(int i = 0;i < n;i++) if(degree[i] == 1) leaves.insert(i);

    vector<pair<int, int>> edges;
    for(int v : code) {
        int leaf = *leaves.begin();
        leaves.erase(leaves.begin());
        edges.emplace_back(leaf, v);
        if(--degree[v] == 1) leaves.insert(v);
    }

    edges.emplace_back(*leaves.begin(), n - 1);
    return edges;
}

int main() {
    int n;
    cin >> n;

    vector<int> code(n);
    for(int i = 0;i < int(code.size());i++) cin >> code[i];
    
    vector<pair<int, int>> edges = pruferDecode(code);

    cout << "The edges are : " << endl;
    for(auto it : edges) cout << it.first << " " << it.second << endl;

    return 0;
}
