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
    build(a, v * 2, tl, tm);
    build(a, v * 2 + 1, tm + 1, tr);

    t[v] = max(t[2 * v], t[2 * v + 1]);
}

int query(int v, int tl, int tr, int l, int r) {
    if(l > r) return 0;

    if(l == tl && r == tr) {
        return t[v];
    }

    int tm = (tl + tr) >> 1;
    return max(query(2 * v, tl, tm, l, min(r, tm)), query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if(tl == tr) {
        t[v] = new_val;
        return;
    }

    int tm = (tl + tr) >> 1;
    if(pos <= tm) {
        update(2 * v, tl, tm, pos, new_val);
    } else {
        update(2 * v + 1, tm + 1, tr, pos, new_val);
    }

    t[v] = max(t[2 * v], t[2 * v + 1]);
}

int main() {
    n = 5;
    int a[] = {1, 2, 3, 4, 5};

    build(a, 1, 0, n - 1);

    printf("0 to 4 : %d\n", query(1, 0, n - 1, 0, 4));
    printf("1 to 3 : %d\n", query(1, 0, n - 1, 1, 3));

    printf("Changing the element at index 1 to 6\n");
    update(1, 0, n - 1, 1, 6);

    printf("0 to 4 : %d\n", query(1, 0, n - 1, 0, 4));
    printf("1 to 3 : %d\n", query(1, 0, n - 1, 1, 3));
    
    return 0;
}
