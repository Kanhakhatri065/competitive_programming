const int INF = 1e9;
const int N = 25;
int n;
vector<int> a;
int t[4 * N];
int lazy[4 * N];

void push(int node) {
    t[node << 1] += lazy[node];
    lazy[node << 1] += lazy[node];
    
    t[node << 1 | 1] += lazy[node];
    lazy[node << 1 | 1] += lazy[node];

    lazy[node] = 0;
}

void update(int node, int tl, int tr, int l, int r, int addend) {
    if(l > r) return;

    if(l == tl && r == tr) {
        t[node] += addend;
        lazy[node] += addend;
        return;
    }

    push(node);
    int tm = (tl + tr) >> 1;
    update(node << 1, tl, tm, l, min(tm, r), addend);
    update(node << 1 | 1, tm + 1, tr, max(l, tm + 1), r, addend);
    t[node] = max(t[node << 1], t[node << 1 | 1]);
}

int query(int node, int tl, int tr, int l, int r) {
    if(l > r) return -INF;

    if(l <= tl && tr <= r) {
        return t[node];
    }

    push(node);
    int tm = (tl + tr) >> 1;
    return max(query(node << 1, tl, tm, l, min(tm, r)), 
            query(node << 1 | 1, tm + 1, tr, max(l, tm + 1), r));
}
