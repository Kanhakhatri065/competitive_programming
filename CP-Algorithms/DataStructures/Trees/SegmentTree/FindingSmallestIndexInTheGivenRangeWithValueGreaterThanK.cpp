#include <bits/stdc++.h>
using namespace std;

const int N = 25;
int n;
int t[4 * N];
vector<int> a;
void build(int node, int tl, int tr) {
    if(tl == tr) {
        t[node] = a[tl];
        return;
    }

    int tm = (tl + tr) >> 1;
    build(node << 1, tl, tm);
    build(node << 1 | 1, tm + 1, tr);
    t[node] = max(t[node << 1], t[node << 1 | 1]);
}

void update(int node, int tl, int tr, int idx, int new_val) {
    if(tl == tr) {
        t[node] = new_val;
        return;
    }

    int tm = (tl + tr) >> 1;
    if(idx <= tm) {
        update(node << 1, tl, tm, idx, new_val);
    } else {
        update(node << 1 | 1, tm + 1, tr, idx, new_val);
    }

    t[node] = max(t[node << 1], t[node << 1 | 1]);
}

int get_first(int node, int tl, int tr, int l, int r, int k) {
    if(tl > r || tr < l) return -1;
    if(l <= tl && tr <= r) {
        if(t[node] <= k) return -1;
        while(tl != tr) {
            int tm = tl + ((tr - tl) >> 1);
            if(t[node << 1] > k) {
                node = node << 1;
                tr = tm;
            } else {
                node = node << 1 | 1;
                tl = tm + 1;
            }
        }

        return tl;
    }

    int tm = (tl + tr) >> 1;
    int rs = get_first(node << 1, tl, tm, l, r, k);
    if(rs != -1) return rs;
    return get_first(node << 1 | 1, tm + 1, tr, l, r, k);
}

int main() {
    cout << "Enter array size : " << endl;
    cin >> n;
    a.resize(n);

    cout << "Enter array elements : " << endl;
    for(int i = 0;i < n;i++) cin >> a[i];

    cout << "Build initiated" << endl;
    build(1, 0, n -1);
    cout << "Build completed" << endl;

    cout << "Enter the number of queries" << endl;
    int q;cin >> q;
    while(q--) {
        cout << "Enter the type of query : " << endl;
        cout << "1. Find min index in the given range with value greater than k" << endl;
        cout << "2. Update" << endl;
        int type;cin >> type;
        if(type == 1) {
            cout << "Enter range and K" << endl;
            int l, r, k;cin >> l >> r >> k;
            int ans = get_first(1, 0, n - 1, l, r, k);
            if(ans == -1) {
                cout << "No element has value greater than " << k << " in the given range" << endl;
            } else {
                cout << "Smallest index with value greater than " << k << " : " << ans << endl;
            }
        } else {
            cout << "Enter index and new value" << endl;
            int idx, new_val;cin >> idx >> new_val;

            cout << "Update initiated" << endl;
            update(1, 0, n - 1, idx, new_val);
            cout << "Update completed" << endl;
        }
    }
    return 0;
}
