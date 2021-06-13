#include <bits/stdc++.h>
using namespace std;

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

int main() {
    cout << "Enter array size : " << endl;
    cin >> n;
    a.resize(n);

    cout << "Enter array elements : " << endl;
    for(int i = 0;i < n;i++) cin >> a[i];

    cout << "Build initiated" << endl;
    build(1, 0, n - 1);
    cout << "Build Completed" << endl;

    cout << "Enter number of queries : " << endl;
    int q;cin >> q;
    while(q--) {
        cout << "Enter type of query :\n1. Min element in given range >= x\n2. Update" << endl;
        int type;cin >> type;
        if(type == 1) {
            cout << "Enter range and x" << endl;
            int l, r, x;cin >> l >> r >> x;
            int ans = query(1, 0, n - 1, l, r, x);
            
            if(ans == INF) {
                cout << "No element in range (" << l << ", " << r << ")" << endl;
            } else {
                cout << "Min element in range(" << l << ", " << r << ") greater than or equal to  " << x << " : " << ans << endl;
            }
        } else {
            cout << "Enter index and new value : " << endl;
            int idx, new_val;cin >> idx >> new_val;

            cout << "Update initiated" << endl;
            update(1, 0, n - 1, idx, new_val);
            cout << "Update completed" << endl;
        }
    }
    return 0;
}
