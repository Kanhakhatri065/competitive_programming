#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int n, m;
void multiply(int a[N][N], int b[N][N], int res[N][N]) {
    int mul[N][N];

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            mul[i][j] = 0;
            for(int k = 0;k < n;k++) mul[i][j] += a[i][k] * b[k][j];
        }
    }

    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) res[i][j] = mul[i][j];
}

void power(int g[N][N], int res[N][N], int k) {
    if(k == 1) {
        for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) res[i][j] = g[i][j];
        return;
    }

    power(g, res, k / 2);
    multiply(g, g, res);
    if(k & 1) multiply(res, g, res);
    
}

int main() {
    cout << "No of vertices : " << endl;
    cin >> n;
    cout << "No of edges : " << endl;
    cin >> m;
    cout << "Enter the edges : " << endl;

    int g[N][N];
    memset(g, 0, sizeof(g));
    for(int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        g[u][v] = 1;
    }
    
    cout << "Enter the length of path : " << endl;
    int k;cin >> k;
    int res[N][N];
    power(g, res, k);

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
