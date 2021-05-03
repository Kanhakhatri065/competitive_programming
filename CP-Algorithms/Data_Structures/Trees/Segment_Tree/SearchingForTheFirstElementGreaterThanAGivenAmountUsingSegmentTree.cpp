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

int get_first(int v, int tl, int tr, int l, int r, int x) {
    if(tl > r || tr < v) return -1;

    if(l <= tl && tr <= r) {
        if(t[v] <= x) return -1;
        while(tl != tr) {
            int mid = tl + (tr - tl) / 2    ;
            if(t[v << 1] > x) {
                v = v << 1;
                tr = mid;
            } else {
                v = v << 1 | 1;
                tl = mid + 1;
            }
        }

        return tl;
    }

    int tm = (tl + tr) >> 1;
    int rs = get_first(v << 1, tl, tm, l, r, x);
    if(rs != -1) return rs;
    return get_first(v << 1 | 1, tm + 1, tr, l, r, x);
}

int main() {
    n = 5;
    int a[] = {1, 2, 3, 4, 5};
    build(a, 1, 0, n - 1);

    cout << "Smallest index with prefix sum greater than 4 in the range 1 to 4 : " << get_first(1, 0, n - 1, 1, 4, 4) << endl;
    return 0;
}