#include <bits/stdc++.h>

using namespace std;

struct Vertex {
    Vertex *l, *r;
    int sum;
    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if(l) sum += l->sum;
        if(r) sum += r->sum;
    }
};

Vertex* build(int a[], int tl, int tr) {
    if(tl == tr) {
        return new Vertex(a[tl]);
    }

    int tm = (tl + tr) >> 1;
    return new Vertex(build(a, tl, tm), build(a, tm + 1, tr));
}

int get_sum(Vertex *v, int tl, int tr, int l, int r) {
    if(l > r) return 0;
    if(l == tl && r == tr) return v->sum;

    int tm = (tl + tr) >> 1;
    return get_sum(v->l, tl, tm, l, min(r, tm)) + get_sum(v->r, tm + 1, tr, max(l, tm + 1), r);
}

Vertex* update(Vertex* v, int tl, int tr, int pos, int new_val) {
    if(tl == tr) {
        return new Vertex(new_val);
    }

    int tm = (tl + tr) >> 1;
    if(pos <= tm) {
        return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
    } else {
        return new Vertex(v->l, update(v->r, tm + 1, tr, pos, new_val));
    }
}

int main() {
    int n = 5;
    int a[] = {1, 2, 3, 4, 5};

    Vertex* root = build(a, 0, n - 1);
    vector<Vertex*> store;
    store.push_back(root);

    cout << "Update index 3 to 8 : " << endl;
    store.push_back(update(store.back(), 0, n - 1, 3, 8));
    cout << "Update index 1 to 6 : " << endl;
    store.push_back(update(store.back(), 0, n - 1, 1, 6));

    cout << "Total sum before any update : " << get_sum(store[0], 0, n - 1, 0, n - 1) << endl;
    cout << "Total sum after firstupdate : " << get_sum(store[1], 0, n - 1, 0, n - 1) << endl;
    cout << "Total sum aftersecondupdate : " << get_sum(store[2], 0, n - 1, 0, n - 1) << endl;

    return 0;
}
