#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
int n, t[4*MAXN];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int main() {
    n = 5;
    int a[] = {1, 2, 3, 4, 5};
    build(a, 1, 0, n - 1);

    cout << "0 to 4 : " << sum(1, 0, n - 1, 0, 4) << endl;
    cout << "1 to 3 : " << sum(1, 0, n - 1, 1, 3) << endl;

    cout << "changing element with index 1 to 6 : " << endl;
    update(1, 0, n - 1, 1, 6);

    cout << "0 to 4 : " << sum(1, 0, n - 1, 0, 4) << endl;
    cout << "1 to 3 : " << sum(1, 0, n - 1, 1, 3) << endl;

    return 0;
}
