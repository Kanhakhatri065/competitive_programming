const int N = 25;
int n;
vector<int> a;
int t[4 * N];
bool marked[4 * N];

void push(int node) {
    if(marked[node]) {
        t[node << 1] = t[node << 1 | 1] = t[node];
        marked[node << 1] = marked[node << 1 | 1] = true;
        marked[node] = false;
    }
}

void update(int node, int tl, int tr, int l, int r, int new_val) {
    if(l > r) return;

    if(l == tl && r == tr) {
        t[node] = new_val;
        marked[node] = true;
        return;
    }

    push(node);
    int tm = (tl + tr) >> 1;
    update(node << 1, tl, tm, l, min(tm, r), new_val);
    update(node << 1 | 1, tm + 1, tr, max(l, tm + 1), r, new_val);
}

int query(int node, int tl, int tr, int idx) {
    if(tl == tr) {
        return t[node];
    }

    push(node);
    int tm = (tl + tr) >> 1;
    if(idx <= tm) {
        return query(node << 1, tl, tm, idx);
    }

    return query(node << 1 | 1, tm + 1, tr, idx);
}
