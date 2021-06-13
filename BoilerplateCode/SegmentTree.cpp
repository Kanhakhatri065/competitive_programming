const int N = 1e5 + 5;
int n;
int t[4 * N];
vector<int> a;
//here node argument is used as pointer to traverse in the segment tree
//In this function first build the children nodes and then merge them
void build(int node, int tl, int tr) {
    if(tl == tr) {
        t[node] = a[tl];
        return;
    }

    int tm = (tl + tr) >> 1;
    build(node << 1, tl, tm);
    build(node << 1 | 1, tm + 1, tr);
    t[node] = t[node << 1] + t[node << 1 | 1];
}

int sum(int node, int tl, int tr, int l, int r) {
    if(l > r) return 0;
    if(l == tl && r == tr) {
        return t[node];
    }

    int tm = (tl + tr) >> 1;
    int ans = sum(node << 1, tl, tm, l, min(r, tm));
    ans += sum(node << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
    return ans;
}

void update(int node, int tl, int tr, int pos, int new_val) {
    if(tl == tr) {
        t[node] = new_val;
        return;
    }

    int tm = (tl + tr) >> 1;
    if(pos <= tm) update(node << 1, tl, tm, pos, new_val);
    else update(node << 1, tm + 1, tr, pos, new_val);
    t[node] = t[node << 1] + t[node << 1 | 1];
}
