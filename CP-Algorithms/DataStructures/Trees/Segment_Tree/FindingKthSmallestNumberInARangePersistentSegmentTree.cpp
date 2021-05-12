#include <bits/stdc++.h>

using namespace std;

struct Vertex {
    Vertex *l, *r;
    int sum;

    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l_, Vertex *r_) : l(l_), r(r_), sum(0) {
        if(l) sum += l->sum;
        if(r) sum += r->sum;
    }
};

Vertex* build(int tl, int tr) {
    if(tl == tr) {
        return new Vertex(0);
    }

    int tm = (tl + tr) >> 1;
    return new Vertex(build(tl, tm), build(tm + 1, tr));
}

Vertex* update(Vertex* v, int tl, int tr, int pos) {
    if(tl == tr) {
        return new Vertex(v->sum + 1);
    }

    int tm = (tl + tr) >> 1;
    if(pos <= tm) {
        return new Vertex(update(v->l, tl, tm, pos), v->r);
    }

    return new Vertex(v->l, update(v->r, tm + 1, tr, pos));
}

int find_kth(Vertex* vl, Vertex *vr, int tl, int tr, int k) {
    if(tl == tr) {
        return tl;
    }

    int tm = (tl + tr) >> 1, left_count = vr->l->sum - vl->l->sum;
    if(left_count >= k) {
        return find_kth(vl->l, vr->l, tl, tm, k);
    }

    return find_kth(vl->r, vr->r, tm + 1, tr, k - left_count);
}

int main() {
    const int MAX = 105;
    vector<Vertex*> roots;
    int tl = 0, tr = MAX + 1;
    vector<int> a({1, 2, 3, 4, 5});
    roots.push_back(build(tl, tr));
    for(int i = 0;i < int(a.size());i++) {
        roots.push_back(update(roots.back(), tl, tr, a[i]));
    }
    
    //find the 2nd smallest from the range 1 to 4
    int result = find_kth(roots[1], roots[4], tl, tr, 3);
    cout << result << endl;

    return 0;
}
