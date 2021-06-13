#include <bits/stdc++.h>
using namespace std;

const int N = 25;
const int INF = 1e9 + 5;
int n;
vector<int> t[4 * N];
vector<int> a;

void build(int node, int tl, int tr) {
    if(tl == tr) {
        t[node] = vector<int>(1, a[tl]);
        return;
    }

    int tm = (tl + tr) >> 1;
    build(node << 1, tl, tm);
    build(node << 1 | 1, tm + 1, tr);
    merge(t[node << 1].begin(), t[node << 1].end(), t[node << 1 | 1].begin(), t[node << 1 | 1].end(),
            back_inserter(t[node]));
}

int query(int node, int tl, int tr, int l, int r, int x) {
    if(l > r) return INF;

    if(l == tl && r == tr) {
        auto pos = lower_bound(t[node].begin(), t[node].end(), x);
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

    cout << "Build Initiated" << endl;
    build(1, 0, n - 1);
    cout << "Build Completed" << endl;

    cout << "Enter number of queries : " << endl;
    int q;cin >> q;
    while(q--) {
        cout << "Enter range and number : " << endl;
        int l, r, x;
        cin >> l >> r >> x;

        int ans = query(1, 0, n - 1, l, r, x);
        if(ans == INF) {
            cout << "All elements present in (" << l << ", " << r << ")" << endl;
        } else {
            cout << "Minimum element present in (" << l << ", " << r << ") :  " << ans << endl;
        }
    }
    return 0;
}
