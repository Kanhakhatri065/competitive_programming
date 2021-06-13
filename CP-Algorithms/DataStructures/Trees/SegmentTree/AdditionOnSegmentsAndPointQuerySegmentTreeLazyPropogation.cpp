#include <bits/stdc++.h>
using namespace std;

const int N = 25;
int n;
vector<int> a;
int t[4 * N];

void build(int node, int tl, int tr) {
    if(tl == tr) {
        t[node] = a[tl];
        return;
    }

    int tm = (tl + tr) >> 1;
    build(node << 1, tl, tm);
    build(node << 1 | 1, tm + 1, tr);
    t[node] = 0;
}

void update(int node, int tl, int tr, int l, int r, int add) {
    if(l > r) return;
    if(l == tl && r == tr) {
        t[node] += add;
        return;
    } 

    int tm = (tl + tr) >> 1;
    update(node << 1, tl, tm, l, min(tm, r), add);
    update(node << 1 | 1, tm + 1, tr, max(l, tm + 1), r, add);
}

int query(int node, int tl, int tr, int pos) {
    if(tl == tr) {
        return t[node];
    }

    int tm = (tl + tr) >> 1;
    if(pos <= tm) {
        return query(node << 1, tl, tm, pos);
    }

    return query(node << 1 | 1, tm + 1, tr, pos);
}

int main() {
    cout << "Enter array size : " << endl;
    cin >> n;
    a.resize(n);

    cout << "Enter array elements : " << endl;
    for(int i = 0;i < n;i++) cin >> a[i];

    cout << "Build initiated" << endl;
    build(1, 0, n - 1);
    cout << "Build completed" << endl;

    cout << "Enter number of queries : " << endl;
    int q;cin >> q;
    while(q--) {
        cout << "Enter the type of query:\n1. Assignments on segments\n2. Point query" << endl;
        int type;cin >> type;

        if(type == 1) {
            cout << "Enter range and addition value" << endl;
            int l, r, add;cin >> l >> r >> add;
            cout << "Adding " << add << " to the segment (" << l << ", " << r << ")" << endl;
            update(1, 0, n - 1, l, r, add);
            cout << "Updation completed" << endl;
        } else {
            cout << "Enter index " << endl;
            int idx;cin >> idx;
            int ans = query(1, 0, n - 1, idx);
            cout << "Value at index " << idx << " is : " << ans << endl;
        }
    }
    return 0;
}
