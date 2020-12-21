#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> v(n + 1, vector<int> (m + 1));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> v[i][j];
    vector<int> mr(n + 1), mc(m + 1);
    for (int i = 1; i <= n; i++) mr[i] = i;
    for (int i = 1; i <= m; i++) mc[i] = i;
    
    while (k--) {
        char s;
        int x, y;
        cin >> s >> x >> y;
        if (s == 'c')
            swap(mc[x], mc[y]);
        else if (s == 'r')
            swap(mr[x], mr[y]);
        else
            cout << v[mr[x]][mc[y]] << "\n";
    }
    
    return 0;
}