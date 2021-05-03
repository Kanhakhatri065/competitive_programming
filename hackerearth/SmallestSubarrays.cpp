#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> t;
vector<int> a, b;
int n;

void build(int node, int tl, int tr) {
    if(tl == tr) {
        t[node].push_back(a[tl]);
        return;
    }

    int tm = (tl + tr) >> 1;
    build(node << 1, tl, tm);
    build(node << 1 | 1, tm + 1, tr);
    merge(t[node << 1].begin(), t[node << 1].end(),
            t[node << 1 | 1].begin(), t[node << 1 | 1].end(),
            back_inserter(t[node]));
}

int query(int node, int tl, int tr, int l, int r, int k) {
    if(l > tr || r < tl) return 0;

    if(tl >= l && tr <= r) {
        return (int(t[node].size()) - (lower_bound(t[node].begin(), t[node].end(), k) - t[node].begin()));
    }

    int tm = (tl + tr) >> 1;
    return query(node << 1, tl, tm, l, r, k) + query(node << 1 | 1, tm + 1, tr, l, r, k);
}

int main() {
    scanf("%d", &n);
    t.resize(4 * n + 5);
    
    a.resize(n);
    for(int i = 0;i < n;i++) scanf("%d", &a[i]);
    b.resize(n);
    for(int i = 0;i < n;i++) scanf("%d", &b[i]);
       
    build(1, 0, n - 1);
    vector<int> res;
    int val, s, e, ans, cnt, m;
    for(int i = 0;i < n;i++) {
        val = a[i], s = i, e = n - 1, ans = -1;
        while(s <= e) {
            m = (s + e) >> 1;
            cnt = query(1, 0, n - 1, i, m, val);
            if(cnt >= b[i]) {
                ans = m;
                e = m - 1;
            } else {
                s = m + 1;
            }
        }

        if(ans == -1) res.push_back(-1);
        else res.push_back(ans - i + 1);
    }

    for(int i = 0;i < n;i++) printf("%d ", res[i]);
    printf("\n");
    return 0;
}
