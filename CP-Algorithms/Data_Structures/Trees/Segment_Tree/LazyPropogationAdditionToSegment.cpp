#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int t[4 * N];

void build(int a[], int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = a[tl];
        return;
    }

    int tm = (tl + tr) >> 1;
    build(a, v << 1, tl, tm);
    build(a, v << 1 | 1, tm + 1, tr);
    t[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int add) {
    if(l > r) return;

    if(l == tl && r == tr) {
        t[v] += add;
        return;
    }

    int tm = (tl + tr) >> 1;
    update(v << 1, tl, tm, l, min(r, tm), add);
    update(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, add);
}

int get(int v, int tl, int tr, int pos) {
    if(tl == tr) {
        return t[v];
    }

    int tm = (tl + tr) >> 1;
    if(pos <= tm) {
        return t[v] + get(v << 1, tl, tm, pos);
    }

    return t[v] + get(v << 1 | 1, tm + 1, tr, pos);
}

int main() {
    int n = 5;
    int a[] = {1, 3, 2, 3, 5};
    cout << "Building : " << endl;
    build(a, 1, 0, n - 1);
    cout << "Updating : " << endl;
    update(1, 0, n - 1, 1, 3, 5);

    cout << "Value at index 2 : " << get(1, 0, n - 1, 2) << endl;

    return 0;
}