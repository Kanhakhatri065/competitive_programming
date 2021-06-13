#include <bits/stdc++.h>
using namespace std;

const int N = 25;
int n;
vector<int> a;
int t[4 * N];
bool marked[4 * N];

void push(int node) {
    if(marked[node]) {
        t[node << 1] = t[node << 1 | 1] = t[node];
        marked[node << 1] = marked[node << 1 | 1] = true;
        marked[node] = false;
    }
}

void update(int node, int tl, int tr, int l, int r, int new_val) {
    if(l > r) return;

    if(l == tl && r == tr) {
        t[node] = new_val;
        marked[node] = true;
        return;
    }

    push(node);
    int tm = (tl + tr) >> 1;
    update(node << 1, tl, tm, l, min(tm, r), new_val);
    update(node << 1 | 1, tm + 1, tr, max(l, tm + 1), r, new_val);
}

int query(int node, int tl, int tr, int idx) {
    if(tl == tr) {
        return t[node];
    }

    push(node);
    int tm = (tl + tr) >> 1;
    if(idx <= tm) {
        return query(node << 1, tl, tm, idx);
    }

    return query(node << 1 | 1, tm + 1, tr, idx);
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

    cout << "Enter number of queries " << endl;
    int q;cin >> q;
    while(q--) {
        cout << "Enter type of queries :\n1. AssignmentOnSegments\n2. Point query" << endl;
        int type;cin >> type;
        if(type == 1) {
            cout << "Enter range and new value : " << endl;
            int l, r, new_val;cin >> l >> r >> new_val;

            update(1, 0, n - 1, l, r, new_val);
            cout << "Update completed" << endl;
        } else {
            cout << "Enter index : " << endl;
            int idx;cin >> idx;
            int ans = query(1, 0, n - 1, idx);
            cout << "Value at index " << idx << " is : " << ans << endl;
        }
    }

    return 0;
}
