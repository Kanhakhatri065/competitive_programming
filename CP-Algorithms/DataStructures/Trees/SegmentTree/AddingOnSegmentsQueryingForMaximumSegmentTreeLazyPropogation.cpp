#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 25;
int n;
vector<int> a;
int t[4 * N];
int lazy[4 * N];

void push(int node) {
    t[node << 1] += lazy[node];
    lazy[node << 1] += lazy[node];
    
    t[node << 1 | 1] += lazy[node];
    lazy[node << 1 | 1] += lazy[node];

    lazy[node] = 0;
}

void update(int node, int tl, int tr, int l, int r, int addend) {
    if(l > r) return;

    if(l == tl && r == tr) {
        t[node] += addend;
        lazy[node] += addend;
        return;
    }

    push(node);
    int tm = (tl + tr) >> 1;
    update(node << 1, tl, tm, l, min(tm, r), addend);
    update(node << 1 | 1, tm + 1, tr, max(l, tm + 1), r, addend);
    t[node] = max(t[node << 1], t[node << 1 | 1]);
}

int query(int node, int tl, int tr, int l, int r) {
    if(l > r) return -INF;

    if(l <= tl && tr <= r) {
        return t[node];
    }

    push(node);
    int tm = (tl + tr) >> 1;
    return max(query(node << 1, tl, tm, l, min(tm, r)), 
            query(node << 1 | 1, tm + 1, tr, max(l, tm + 1), r));
}

int main() {
    cout << "Enter array size : " << endl;
    cin >> n;
    a.resize(n);

    cout << "Enter array elements : " << endl;
    for(int i = 0;i < n;i++) cin >> a[i];

    cout << "Build initiated" << endl;
    for(int i = 0;i < n;i++) update(1, 0, n - 1, i, i, a[i]);
    cout << "Build completed" << endl;

    cout << "Enter number of queries : " << endl;
    int q;cin >> q;
    while(q--) {
        cout << "Enter the type of query :\n1. Addition On Segments\n2. Max range query" << endl;
        int type;cin >> type;
        if(type == 1) {
            cout << "Enter range and addend" << endl;
            int l, r, addend;cin >> l >> r >> addend;
            update(1, 0, n - 1, l, r, addend);
            cout << "Update completed" << endl;
        } else {
            cout << "Enter range " << endl;
            int l, r;cin >> l >> r;

            int ans = query(1, 0, n - 1, l, r);

            cout << "Max in the range (" << l << ", " << r << ") : " << ans << endl;
        }
    }
    return 0;
}
