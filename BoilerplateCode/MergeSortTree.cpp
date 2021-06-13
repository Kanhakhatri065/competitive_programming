const int N = 25;
const int INF = 1e9 + 5;
int n;
vector<int> a;
multiset<int> t[4 * N];

void build(int node, int tl, int tr) {
    if(tl == tr) {
        t[node].clear();
        t[node].insert(a[tl]);
        return;
    }

    int tm = (tl + tr) >> 1;
    build(node << 1, tl, tm);
    build(node << 1 | 1, tm + 1, tr);
    merge(t[node << 1].begin(), t[node << 1].end(), t[node << 1 | 1].begin(), t[node << 1 | 1].end(), 
            inserter(t[node], t[node].begin()));
}

void update(int node, int tl, int tr, int idx, int new_val) {
    t[node].erase(t[node].find(a[idx]));
    t[node].insert(new_val);

    if(tl == tr) {
        a[idx] = new_val;
        return;
    }

    int tm = (tl + tr) >> 1;
    if(idx <= tm) {
        update(node << 1, tl, tm, idx, new_val);
    } else {
        update(node << 1 | 1, tm + 1, tr, idx, new_val);
    }
}

int query(int node, int tl, int tr, int l, int r, int x) {
    if(l > r) {
        return INF;
    }

    if(l == tl && r == tr) {
        auto pos = t[node].lower_bound(x);
        if(pos != t[node].end()) {
            return *pos;
        }
        return INF;
    }

    int tm = (tl + tr) >> 1;
    return min(query(node << 1, tl, tm, l, min(tm, r), x), 
            query(node << 1 | 1, tm + 1, tr, max(l, tm + 1), r, x));
}
