#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int INF = 1e9;

multiset<int> t[4 * N];

void build(int a[], int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = multiset<int>();
        t[v].insert(a[tl]);
        return;
    }

    int tm = (tl + tr) >> 1;
    build(a, v << 1, tl, tm);
    build(a, v << 1 | 1, tm + 1, tr);
    t[v] = t[v << 1];   
    t[v].insert(t[v << 1 | 1].begin(), t[v << 1 | 1].end());
}

int query(int v, int tl, int tr, int l, int r, int x) {
    if(l > r) return INF;

    if(l == tl && r == tr) {
        auto pos = t[v].lower_bound(x);
        if(pos != t[v].end()) {
            return *pos;
        }

        return INF;
    }

    int tm = (tl + tr) >> 1;
    return min(query(v << 1, tl, tm, l, min(r, tm), x), query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, x));
}

void update(int a[], int v, int tl, int tr, int pos, int new_val) {
    t[v].erase(t[v].find(a[pos]));
    t[v].insert(new_val);

    if(tl == tr) {
        a[pos] = new_val;
    } else {
        int tm = (tl + tr) >> 1;
        if(pos <= tm) {
            update(a, v << 1, tl, tm, pos, new_val);
        } else {
            update(a, v << 1 | 1, tm + 1, tr, pos, new_val);
        }
    }
}

int main() {
    int n = 5;
    int a[] = {1, 3, 2, 4, 5};
    build(a, 1, 0, n - 1);

    cout << "Smallest number b/w 1 to 3 greater than or equal to 2 : " << query(1, 0, n - 1, 1, 3, 2) << endl;

    cout << "Updating value at index 2 to 3" << endl;
    update(a, 1, 0, n - 1, 2, 3);

    cout << "Smallest number b/w 1 to 3 greater than or equal to 2 : " << query(1, 0, n - 1, 1, 3, 2) << endl;

    return 0;
}