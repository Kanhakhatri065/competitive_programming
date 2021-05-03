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
    t[v] = t[v << 1] + t[v << 1 | 1];
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

    t[v] = t[v << 1] + t[v << 1 | 1];
}

int query(int v,int tl, int tr, int x) {
    if(tl == tr) {
        return tl;
    }

    int tm = (tl + tr) >> 1;

    if(t[v << 1] >= x) {
        return query(v << 1, tl, tm, x);
    }

    return query(v << 1 | 1, tm + 1, tr, x - t[v << 1]);
}

int main() {
    n = 5;
    int a[] = {1, 2, 3, 4, 5};
    
    build(a, 1, 0, n - 1);

    int x = 5;
    cout << "Smallest index with prefix sum greater than or equal to 5 : " << query(1, 0, n - 1, x) << endl;
    cout << "Smallest index with prefix sum greater than or equal to 10 : " << query(1, 0, n - 1, 10) << endl;

    cout << "Update element at index 1 to 4" << endl;
    update(1, 0, n - 1, 1, 4);

    cout << "Smallest index with prefix sum greater than or equal to 5 : " << query(1, 0, n - 1, x) << endl;
    cout << "Smallest index with prefix sum greater than or equal to 10 : " << query(1, 0, n - 1, 10) << endl;

    return 0;
}