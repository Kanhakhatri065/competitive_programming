#include <bits/stdc++.h>
using namespace std;

struct Data {
    int sum, pref, suff, ans;
};

Data combine(Data l, Data r) {
    Data res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum +  r.pref);
    res.suff = max(r.suff, l.suff + r.sum);
    res.ans = max({l.ans, r.ans, l.suff + r.pref});
    return res;
}

Data make_Data(int val) {
    Data res;
    res.sum = val;
    res.pref = res.suff = res.ans = max(val, 0);
    return res;
}

const int N = 25;
int n;
vector<int> a;
Data t[4 * N];

void build(int node, int tl, int tr) {
    if(tl == tr) {
        t[node] = make_Data(a[tl]);
        return;
    }

    int tm = (tl + tr) >> 1;
    build(node << 1, tl, tm);
    build(node << 1 | 1, tm + 1, tr);
    t[node] = combine(t[node << 1], t[node << 1 | 1]);
}

void update(int node, int tl, int tr, int pos, int new_val) {
    if(tl == tr) {
        t[node] = make_Data(new_val);
        return;
    }

    int tm = (tl + tr) >> 1;
    if(pos <= new_val) {
        update(node << 1, tl, tm, pos, new_val);
    } else {
        update(node << 1 | 1, tm + 1, tr, pos, new_val);
    }

    t[node] = combine(t[node << 1], t[node << 1 | 1]);
}

Data query(int node, int tl, int tr, int l, int r) {
    if(l > r) {
        return make_Data(0);
    }

    if(l == tl && r == tr) {
        return t[node];
    }

    int tm = (tl + tr) >> 1;
    return combine(query(node << 1, tl, tm, l, min(tm, r)), 
            query(node << 1 | 1, tm + 1, tr, max(l, tm + 1), r));
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

    cout << "Enter the number of queries : " << endl;
    int q;cin >> q;
    while(q--) {
        cout << "Enter the type of query :\n1. Max sum in a segment\n2. Update" << endl;
        int type;cin >> type;
        if(type == 1) {
            cout << "Enter the range : " << endl;
            int l, r;cin >> l >> r;
            Data tmp = query(1, 0, n - 1, l, r);
            cout << "Maximal sum in the range(" << l << ", " << r << ") : " << tmp.ans << endl;
        } else {
            cout << "Enter index and new value " << endl;
            int idx, new_val;cin >> idx >> new_val;

            cout << "Update initiated" << endl;
            update(1, 0, n - 1, idx, new_val);
            cout << "Update completed" << endl;
        }
    }
    return 0;
}
