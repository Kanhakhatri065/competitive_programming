#include <bits/stdc++.h>
using namespace std;

int lcm(int a, int b) {
    if(a == 0) return b;
    if(b == 0) return a;
    return (a * b) / __gcd(a, b);
}

const int N = 25;
int n;
int t[4 * N];

vector<int> a;
void build(int node, int tl, int tr) {
    if(tl == tr) {
        t[node] = a[tl];
        return;
    }

    int tm = (tl + tr) >> 1;
    build(node << 1, tl, tm);
    build(node << 1 | 1, tm + 1, tr);
    t[node] = lcm(t[node << 1], t[node << 1 | 1]);
}

void update(int node, int tl, int tr, int idx, int new_val) {
    if(tl == tr) {
        t[node] = new_val;
        return;
    }

    int tm = (tl + tr) >> 1;
    if(idx <= tm) {
        update(node << 1, tl, tm, idx, new_val);
    } else {
        update(node << 1 | 1, tm + 1, tr, idx, new_val);
    }

    t[node] = lcm(t[node << 1], t[node << 1 | 1]);
}

int query(int node, int tl, int tr, int l, int r) {
    if(l > r) {
        return 0;
    }

    if(l == tl && r == tr) {
        return t[node];
    }

    int tm = (tl + tr) >> 1;
    return lcm(query(node << 1, tl, tm, l, min(tm, r)), 
    query(node << 1 | 1, tm + 1, tr, max(l, tm + 1), r));
}

int main() {
    cout << "Enter array size : " << endl;
    cin >> n;
    a.resize(n);
    
    cout << "Enter array of elements : " << endl;
    for(int i = 0;i < n;i++) cin >> a[i];

    cout << "Build initiated" << endl;
    build(1, 0, n - 1);
    cout << "Build completed" << endl;

    cout << "Enter number of queries" << endl;
    int q;cin >> q;
    while(q--) {
        cout << "Enter the type of query :\n1. LCM\n2. Update" << endl;
        int type;cin >> type;
        if(type == 1) {
            cout << "Enter range" << endl;
            int l, r;cin >> l >> r;
            int ans = query(1, 0, n - 1, l, r);
            cout << "LCM of range(" << l << ", " << r << ") : " << ans << endl;
        } else {
            cout << "Enter index and new value" << endl;
            int idx, new_val;cin >> idx >> new_val;

            cout << "Update initiated" << endl;
            update(1, 0, n - 1, idx, new_val);
            cout << "Update completed" << endl;
        }
    }
    
    return 0;
}