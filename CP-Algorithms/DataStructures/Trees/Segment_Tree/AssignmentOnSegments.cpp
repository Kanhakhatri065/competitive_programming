#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int t[4 * N];
bool marked[4 * N];

void push(int v) {
    if(marked[v]) {
        t[v << 1] = t[v << 1 | 1] = t[v];
        marked[v << 1] = marked[v << 1 | 1] = true;
        marked[v] = false;
    }
}

void build(int a[], int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = a[tl];
        marked[v] = true;
        return;
    }

    push(v);
    int tm = (tl + tr) >> 1;
    build(a, v << 1, tl, tm);
    build(a, v << 1 | 1, tm + 1, tr);
}

void update(int v, int tl, int tr, int l, int r, int new_val) {
    if(l > r) return;

    if(l == tl && r == tr) {
        t[v] = new_val;
        marked[v] = true;
        return;
    }

    push(v);
    int tm = (tl + tr) >> 1;
    update(v << 1, tl, tm, l, min(r, tm), new_val);
    update(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, new_val);
}

int get(int v, int tl, int tr, int pos) {
    if(tl == tr) {
        return t[v];
    }

    push(v);
    int tm = (tl + tr) >> 1;
    if(pos <= tm) {
        return get(v << 1, tl, tm, pos);
    } else {
        return get(v << 1 | 1, tm + 1, tr, pos);
    }
}

int main() {
    int n = 6;
    int a[] = {1, 3, 2, 3, 4, 5};
    build(a, 1, 0, n - 1);

    cout << "Value at index 2 : " << get(1, 0, n - 1, 2) << endl;
    cout << "Update value from index 1 to 3 to 5 : " << endl;
    update(1, 0, n - 1, 1, 3, 5);
    cout << "Value at index 2 : " << get(1, 0, n - 1, 2) << endl;

    return 0;
}