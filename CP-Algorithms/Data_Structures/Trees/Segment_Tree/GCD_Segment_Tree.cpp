#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, t[4 * N];

void build(int a[], int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = a[tl];
        return;
    }

    int tm = (tl + tr) >> 1;
    build(a, v << 1, tl, tm);
    build(a, v << 1 | 1, tm + 1, tr);

    t[v] = __gcd(t[v << 1], t[v << 1 | 1]);
}

int query(int v, int tl, int tr, int l, int r) {
    if(l > r) return 0;
    
    if(l == tl && r == tr) {
        return t[v];
    }

    int tm = (tl + tr) >> 1;
    return __gcd(query(v << 1, tl, tm, l, min(r, tm)), query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if(tl == tr) {
        t[v] = new_val;
        return;
    }

    int tm = (tl + tr) >> 1;
    if(pos <= tm) {
        update(v << 1, tl, tm, pos, new_val);
    } else {
        update(v << 1 | 1, tm + 1, tr, pos, new_val);
    }

    t[v] = __gcd(t[v << 1], t[v << 1 | 1]);
}

int main() {
    n = 5;

    int a[] = {2, 4, 8, 16, 32};
    build(a, 1, 0, n - 1);

    cout << "GCD from 0 to 4 : " << query(1, 0, n - 1, 0, 4) << endl;
    cout << "GCD from 1 to 3 : " << query(1, 0, n - 1, 1, 3) << endl;
    
    cout << "Update value at index 1 to 8 " << endl;
    update(1, 0, n - 1, 1, 8);

    cout << "GCD from 0 to 4 : " << query(1, 0, n - 1, 0, 4) << endl;
    cout << "GCD from 1 to 3 : " << query(1, 0, n - 1, 1, 3) << endl;

    return 0;
}
