#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 20;
int n;
pair<int, int> t[4 * N];

pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
    if(a.first < b.first) return a;
    if(a.first > b.first) return b;
    return {a.first, a.second + b.second};
}

void build(vector<int> a, int node, int tl, int tr) {
    if(tl == tr) {
        t[node] = {a[tl], 1};
        return;
    }

    int tm = (tl + tr) >> 1;
    build(a, node << 1, tl, tm);
    build(a, node << 1 | 1, tm + 1, tr);
    t[node] = combine(t[node << 1], t[node << 1 | 1]);
}

void update(int node, int tl, int tr, int pos, int new_val) {
    if(tl == tr) {
        t[node] = {new_val, 1};
        return;
    }

    int tm = (tl + tr) >> 1;
    if(pos <= tm) {
        update(node << 1, tl, tm, pos, new_val);
    } else {
        update(node << 1 | 1, tm + 1, tr, pos, new_val);
    }

    t[node] = combine(t[node << 1], t[node << 1 | 1]);
}

pair<int, int> query(int node, int tl, int tr, int l, int r) {
    if(l > r) return {INF, 0};

    if(l == tl && r == tr) {
        return t[node];
    }

    int tm = (tl + tr) >> 1;
    return combine(query(node << 1, tl, tm, l, min(r, tm)), 
    query(node << 1 | 1, tm + 1, tr, max(l, tm + 1), r));
}

int main() {
    cout << "Enter array size : " << endl;
    cin >> n;

    cout << "Enter array elements : " << endl;
    vector<int> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];

    cout << "Build Initiated" << endl;
    build(a, 1, 0, n - 1);
    cout << "Build Completed" << endl;

    cout << "Enter number of queries : " << endl;
    int q;cin >> q;
    while(q--) {
        cout << "Enter the type of query : \n1. Min and occurence\n2.Update" << endl;
        int type;cin >> type;
        if(type == 1) {
            cout << "Enter the range : " << endl;
            int l, r;cin >> l >> r;
            pair<int, int> ans = query(1, 0, n - 1, l, r);
            cout << "Min in the range (" << l << ", " << r << ") is : " << ans.first;
            cout << " and the number of times it occures : " << ans.second << endl;
        } else {
            cout << "Enter index and new value : " << endl;
            int idx, new_val;
            cin >> idx >> new_val;

            cout << "Update initiated" << endl;
            update(1, 0, n - 1, idx, new_val);
            cout << "Update completed" << endl;
        }
    }

    return 0;
}