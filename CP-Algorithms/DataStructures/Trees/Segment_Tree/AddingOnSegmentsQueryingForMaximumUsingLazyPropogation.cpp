#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int INF = 1e9;

int t[4 * N], lazy[4 * N];

void push(int v) {
    t[v << 1] += lazy[v];
    lazy[v << 1] += lazy[v];
    t[v << 1 | 1] += lazy[v];
    lazy[v << 1 | 1] += lazy[v];
    lazy[v] = 0;
}

void build(int a[], int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = a[tl];
        lazy[v] = a[tl];
        return;
    }

    push(v);
    int tm = (tl + tr) >> 1;
    build(a, v << 1, tl, tm);
    build(a, v << 1 | 1, tm + 1, tr);
    t[v] = max(t[v << 1], t[v << 1 | 1]);
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if(l > r) return;

    if(l == tl && r == tr) {
        t[v] += addend;
        lazy[v] += addend;
        return;
    }

    push(v);
    int tm = (tl + tr) >> 1;
    update(v << 1, tl, tm, l, min(r, tm), addend);
    update(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, addend);
    t[v] = max(t[v << 1], t[v << 1 | 1]);
}

int query(int v, int tl, int tr, int l, int r) {
    if(l > r) return -INF;

    if(l == tl && r == tr) {
        return t[v];
    }

    push(v);
    int tm = (tl + tr) >> 1;
    return max(query(v << 1, tl, tm, l, min(r, tm)), query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r));
}

int main() {
    int n = 5;
    int a[] = {1, 3, 2, 1, 4, 5};
    build(a, 1, 0, n - 1);

    cout << "Max from range 1 to 3 : " << query(1, 0, n - 1, 1, 3) << endl;
    cout << "Adding 2 to index 2" << endl;
    update(1, 0, n - 1, 2, 2, 2);
    cout << "Max from range 1 to 3 : " << query(1, 0, n - 1, 1, 3) << endl; 

    return 0;
}