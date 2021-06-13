#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;
const int N = 20;
int n;
int t[4 * N];

void build(vector<int> a, int node, int tl, int tr) {
    if(tl == tr) {
        t[node] = a[tl];
        return;
    }

    int tm = (tl + tr) >> 1;
    build(a, node << 1, tl, tm);
    build(a, node << 1 | 1, tm + 1, tr);
    t[node] = min(t[node << 1], t[node << 1 | 1]);
}

void update(int node, int tl, int tr, int pos, int new_val) {
    if(tl == tr) {
        t[node] = new_val;
        return;
    }

    int tm = (tl + tr) >> 1;
    if(pos <= new_val) {
        update(node << 1, tl, tm, pos, new_val);
    } else {
        update(node << 1 | 1, tm + 1, tr, pos, new_val);
    }

    t[node] = min(t[node << 1], t[node << 1 | 1]);
}

int query(int node, int tl, int tr, int l, int r) {
    if(l > r) return INF;

    if(l == tl && r == tr) {
        return t[node];
    }

    int tm = (tl + tr) >> 1;
    return min(query(node << 1, tl, tm, l, min(r, tm)), query(node << 1 | 1, tm + 1, tr, max(l, tm + 1), r));
}

int main() {
    cout << "Enter the size of the array : " << endl;
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array : " << endl;
    for(int i = 0;i < n;i++) cin >> a[i];

    cout << "Build initiated" << endl;
    build(a, 1, 0, n - 1);
    cout << "Build completed" << endl;

    cout << "Enter the number of queries : " << endl;
    int q;
    cin >> q;
    while(q--) {
        cout << "Enter the type of query : \n1. Min\n2. Update" << endl;
        int type;cin >> type;
        if(type == 1) {
            cout << "Enter the range for Max query : " << endl;
            int l, r;cin >> l >> r;
            int ans = query(1, 0, n - 1, l, r);

            cout << "Min of elements in the range (" << l << ", " << r << ") : " << ans << endl; 
        } else {
            cout << "Input index and new value : " << endl;
            int idx, new_val;
            cin >> idx >> new_val;

            cout << "Update initiated" << endl;
            update(1, 0, n - 1, idx, new_val);
            cout << "Update completed" << endl;
        }
    }
    return 0;
}