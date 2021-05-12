#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;

const int N = 1e5 + 5;
const int INF = 1e9;
int n;
pi t[4 * N];

pi combine(pi a, pi b) {
    if(a.first > b.first) return a;
    if(b.first > a.first) return b;

    return {a.first, a.second + b.second};
}

void build(int a[], int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = {a[tl], 1};
        return;
    }

    int tm = (tl + tr) >> 1;
    build(a, v * 2, tl, tm);
    build(a, v * 2 + 1, tm + 1, tr);

    t[v] = combine(t[v * 2], t[v * 2 + 1]);
}

pi get_max(int v, int tl, int tr, int l, int r) {
    if(l > r) return {-INF, 0};

    if(l == tl && r == tr) {
        return t[v];
    }

    int tm = (tl + tr) >> 1;
    return combine(get_max(2 * v, tl, tm, l, min(r, tm)), get_max(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if(tl == tr) {
        t[v] = {new_val, 1};
        return;
    }

    int tm = (tl + tr) >> 1;
    if(pos <= tm) {
        update(2 * v, tl, tm, pos, new_val);
    } else {
        update(2 * v + 1, tm + 1, tr, pos, new_val);
    }

    t[v] = combine(t[2 * v], t[2 * v + 1]);
}

int main() {
    n = 5;
    int a[] = {5, 5, 5, 3, 4};
    build(a, 1, 0, n - 1);
    
    pi mx = get_max(1, 0, n - 1, 0, 4);
    cout << "Max from 0 to 4 and its number of occurences : " << mx.first << " " << mx.second << endl;
    mx = get_max(1, 0, n -1, 1, 3);
    cout << "Max from 1 to 3 and its number of occurences : " << mx.first << " " << mx.second << endl;

    cout << "Update the element at index at 1 to 4" << endl;
    update(1, 0, n - 1, 1, 4);
    
    mx = get_max(1, 0, n - 1, 0, 4);
    cout << "Max from 0 to 4 and its number of occurences : " << mx.first << " " << mx.second << endl;
    mx = get_max(1, 0, n - 1, 1, 3);
    cout << "Max from 1 to 3 and its number of occurences : " << mx.first << " " << mx.second << endl;

    return 0;
}
