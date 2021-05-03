#include <bits/stdc++.h>

using namespace std;

struct Node {
    int sum, pref, suff, ans;
};

Node combine(Node l, Node r) { 
    Node res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max({l.ans, r.ans, l.suff + r.pref});
    return res;
}

Node createNode(int val) {
    Node res;
    res.sum = val;
    res.pref = res.suff = res.ans = max(0, val);
    return res;
}

const int N = 1e5 + 5;
Node t[4 * N];

void build(int a[], int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = createNode(a[tl]);
        return;
    }

    int tm = (tl + tr) >> 1;
    build(a, v << 1, tl, tm);
    build(a, v << 1 | 1, tm + 1, tr);
    t[v] = combine(t[v << 1], t[v << 1 | 1]);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if(tl == tr) {
        t[v] = createNode(new_val);
        return;
    };

    int tm = (tl + tr) >> 1;
    if(pos <= tm) {
        update(v << 1, tl, tm, pos, new_val);
    } else {
        update(v << 1 | 1, tm + 1, tr, pos, new_val);
    }

    t[v] = combine(t[v << 1], t[v << 1 | 1]);
}

Node query(int v, int tl, int tr, int l, int r) {
    if(l > r) return createNode(0);

    if(l == tl && r == tr) return t[v];

    int tm = (tl + tr) >> 1;
    return combine(query(v << 1, tl, tm, l, min(r, tm)), query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r));
}

int main() {
    int n = 5;
    int a[] = {1, 2, 3, -1, -2};
    build(a, 1, 0, n - 1);

    cout << "Maximum subsegment sum for range 1 to 4 : " << query(1, 0, n - 1, 1, 4).ans << endl;
    return 0;
}