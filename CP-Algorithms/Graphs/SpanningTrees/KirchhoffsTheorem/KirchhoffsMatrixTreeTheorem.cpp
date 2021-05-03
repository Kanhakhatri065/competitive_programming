#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n;
int deg[N];
vector<int> adj[N];
int adj_matrix[N][N];

int main() {
    cin >>  n;
    int m;
    for(int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }

    for(int i = 0;i < n;i++) deg[i] = int(adj[i].size());
    
    memset(adj_matrix, 0, sizeof(adj_matrix));
    for(int i = 0;i < n;i++) {
        for(int v : adj[i]) {
            adj_matrix[i][v] = -1;
        }
    }

    for(int i = 0;i < n;i++) adj_matrix[i][i] = deg[i];
    
    //find cofactor of any element it will be the number of spanning trees

    return 0;
}
