#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, t[4 * N];

void build(int a[], int v, int tl, int tr) {
    if(tl == tr) {
        if(a[tl] == 0) {
            t[v] = 1;
        } else {
            t[v] = 0;
        }

        return;
    }

    int tm = (tl + tr) >> 1;

    build(a, v << 1, tl, tm);
    build(a, v << 1 | 1, tm + 1, tr);
    t[v] = t[v << 1] + t[v << 1 | 1];
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if(tl == tr) {
        if(new_val == 0) {
            t[v] = 1;
        } else {
            t[v] = 0;
        }

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

int find_kth(int v, int tl, int tr, int k) {
    if(k > t[v]) return -1;
    if(tl == tr) return tl;

    int tm = (tl + tr) >> 1;
    if(t[v << 1] >= k) {
        return find_kth(v << 1, tl, tm, k);
    }

    return find_kth(v << 1 | 1, tm + 1, tr, k - t[v << 1]);
}

int main() {
    n = 5;
    int a[] = {0, 1, 0, 1, 0};

    build(a, 1, 0, n - 1);

    cout << "First set of queries" << endl;
    cout << "2nd zero is at index : " << find_kth(1, 0, n - 1, 2) << endl;
    cout << "3rd zero is at index : " << find_kth(1, 0, n - 1, 3) << endl;

    update(1, 0, n - 1, 1, 0);
    cout << "2nd zero is at index : " << find_kth(1, 0, n - 1, 2) << endl;
    cout << "3rd zero is at index : " << find_kth(1, 0, n - 1, 3) << endl;
    
    return 0;
}