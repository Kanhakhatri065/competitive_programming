#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;
vector<int> t[4 * N];

void build(int a[], int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = vector<int>(1, a[tl]);
        return;
    }

    int tm = (tl + tr) >> 1;
    build(a, v << 1, tl, tm);
    build(a, v << 1 | 1, tm + 1, tr);
    merge(t[v << 1].begin(), t[v << 1].end(), t[v << 1 | 1].begin(), t[v << 1 | 1].end(), back_inserter(t[v]));
}

int query(int v, int tl, int tr, int l, int r, int x) {
    if(l > r) return INF;

    if(l == tl && r == tr) {
        auto pos = lower_bound(t[v].begin(), t[v].end(), x);
        if(pos != t[v].end()) {
            return *pos;
        }

        return INF;
    }

    int tm = (tl + tr) >> 1;

    return min(query(v << 1, tl, tm, l, min(r, tm), x), query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, x));
}

int main() {
    int n = 5; 
    int a[] = {1, 3, 2, 4, 5};
    build(a, 1, 0, n - 1);

    cout << "Smallest number between 0 to 3 which is greater than or equal to 2 : " << query(1, 0, n - 1, 0, 3, 2) << endl;
    return 0;
}
