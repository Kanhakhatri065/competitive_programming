#include <bits/stdc++.h>
using namespace std;

struct Vertex {
    Vertex *l, *r;
    int sum;

    Vertex(int val) {
        l = nullptr;
        r = nullptr;
        sum = val;
    }

    Vertex(Vertex *l, Vertex *r) {
        this->l = l;
        this->r = r;
        sum = 0;
        if(l) sum += l->sum;
        if(r) sum += r->sum;
    }
};

Vertex* build(vector<int> a, int tl, int tr) {
    if(tl == tr) return new Vertex(a[tl]);

    int tm = (tl + tr) >> 1;
    return new Vertex(build(a, tl, tm), build(a, tm + 1, tr));
}

int get_sum(Vertex *v, int tl, int tr, int l, int r) {
    if(l > r) return 0;

    if(l == tl && r == tr) {
        return v->sum;
    }

    int tm = (tl + tr) >> 1;
    return get_sum(v->l, tl, tm, l, min(tm, r)) + 
        get_sum(v->r, tm + 1, tr, max(l, tm + 1), r);
}

Vertex* update(Vertex *v, int tl, int tr, int pos, int new_val) {
    if(tl == tr) return new Vertex(new_val);

    int tm = (tl + tr) >> 1;
    if(pos <= tm) {
        return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
    } else {
        return new Vertex(v->l, update(v->r, tm + 1, tr, pos, new_val));
    }
}

int main() {
    cout << "Enter array size : " << endl;
    int n;cin >> n;

    cout << "Enter array elements : " << endl;
    vector<int> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    
    vector<Vertex*> roots;
    cout << "Build initiated" << endl;
    roots.push_back(build(a, 0, n - 1));
    cout << "Build completed" << endl;

    cout << "Enter number of queries : " << endl;
    int q;cin >> q;
    while(q--) {
        cout << "Enter type of query :\n1. Sum\n2. Update : " << endl;
        int type;cin >> type;
        if(type == 1) {
            cout << "Enter version and range : " << endl;
            int root, l, r;cin >> root >> l >> r;

            int ans = get_sum(roots[root - 1], 0, n - 1, l, r);
            cout << "In version " << root << " sum of elements in range (" << l << ", " << r << ") : " << ans << endl;
        } else {
            cout << "Enter index and new value : " << endl;
            int idx, new_val;cin >> idx >> new_val;

            cout << "Update initiated : " << endl;
            roots.push_back(update(roots.back(), 0, n - 1, idx, new_val));
            cout << "Update completed" << endl;
        }
    }
    return 0;
}
