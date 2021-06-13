#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
int t[4 * N];
vector<int> a;
//here node argument is used as pointer to traverse in the segment tree
//In this function first build the children nodes and then merge them
void build(int node, int tl, int tr) {
    if(tl == tr) {
        t[node] = a[tl];
        return;
    }

    int tm = (tl + tr) >> 1;
    build(node << 1, tl, tm);
    build(node << 1 | 1, tm + 1, tr);
    t[node] = t[node << 1] + t[node << 1 | 1];
}

int sum(int node, int tl, int tr, int l, int r) {
    if(l > r) return 0;
    if(l == tl && r == tr) {
        return t[node];
    }

    int tm = (tl + tr) >> 1;
    int ans = sum(node << 1, tl, tm, l, min(r, tm));
    ans += sum(node << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
    return ans;
}

void update(int node, int tl, int tr, int pos, int new_val) {
    if(tl == tr) {
        t[node] = new_val;
        return;
    }

    int tm = (tl + tr) >> 1;
    if(pos <= tm) update(node << 1, tl, tm, pos, new_val);
    else update(node << 1, tm + 1, tr, pos, new_val);
    t[node] = t[node << 1] + t[node << 1 | 1];
}

int main() {
    cout << "Enter the size of the array : " << endl;
    cin >> n;
    a.resize(n);
    cout << "Enter the elements of the array : " << endl;
    for(int i = 0;i < n;i++) cin >> a[i];

    cout << "Build initiated" << endl;
    build(1, 0, n - 1);
    cout << "Build completed" << endl;

    cout << "Enter the number of queries : " << endl;
    int q;
    cin >> q;
    while(q--) {
        cout << "Enter the type of query : \n1. Sum\n2. Update" << endl;
        int type;cin >> type;
        if(type == 1) {
            cout << "Enter the range for sum query : " << endl;
            int l, r;cin >> l >> r;
            int ans = sum(1, 0, n - 1, l, r);

            cout << "Sum of elements in the range (" << l << ", " << r << ") : " << ans << endl; 
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
