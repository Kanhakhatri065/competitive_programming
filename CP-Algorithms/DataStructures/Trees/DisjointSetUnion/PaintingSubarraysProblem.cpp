#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int par[N], ans[N];

struct query {
    int l, r, c;
};

query queries[N];

void make_set(int v) {
    par[v] = v;
}

int find_set(int v) {
    if(v == par[v]) return v;
    return par[v] = find_set(par[v]);
}

int main() {
    int n, m;
    cin >> n >> m;

    fill(ans, ans + n, 0);
    for(int i = 1;i <= n;i++) {
        make_set(i);
    }

    for(int i = 0;i < m;i++) {
        int l, r, c;
        cin >> l >> r >> c;
        queries[i] = {l, r, c};
    }
    
    cout << "Initial parent array : ";
    for(int i = 0;i < n;i++) cout << par[i] << " ";
    cout << endl;
    for(int i = m - 1;i >= 0;i--) {
        int l = queries[i].l, r = queries[i].r, c = queries[i].c;
        for(int v = find_set(l);v <= r;v = find_set(v)) {
            cout << "v is : " << v << " and par of " << v << " is : " << (v + 1) << endl;
            ans[v] = c;
            par[v] = v + 1;
        }
        
        cout << "parent array : ";
        for(int j = 0;j < n;j++) cout << par[i] << " ";
        cout << endl;
        cout << "answer array : ";
        for(int j = 0;j < n;j++) cout << ans[i] << " ";
        cout << endl;
    }

    for(int i = 0;i < n;i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}
