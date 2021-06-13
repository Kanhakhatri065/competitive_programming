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
    t[node] = t[node << 1] + t[node << 1 | 1];
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

    t[node] = t[node << 1] + t[node << 1 | 1];
}

int min_idx(int node, int tl, int tr, int k) { 
    if(tl == tr) return tl;

    int tm = (tl + tr) >> 1;
    if(t[node << 1] >= k) {
        return min_idx(node << 1, tl, tm, k);
    }
    return min_idx(node << 1, tm + 1, tr, k - t[node << 1]);
}

int main() {
    cout << "enter array size : " << endl;
    cin >> n;
    a.resize(n);

    cout << "Enter array elements : " << endl;
    for(int i = 0;i < n;i++) cin >> a[i];

    cout << "Build initiated" << endl;
    build(1, 0, n - 1);
    cout << "Build completed" << endl;

    cout << "Enter number of queries : " << endl;
    int q;cin >> q;
    while(q--) {
        cout << "Enter type of query :\n1. Min idx\n2. Update" << endl;
        int type;cin >> type;
        if(type == 1) {
            cout << "Enter k to find the min idx till which the prefix sum is greater than of equal to k" << endl;
            int k;cin >> k;
            int idx = min_idx(1, 0, n - 1, k);
            if(idx == -1) {
                cout << "The value " << k << " is greater then sum of all elements in the array " << endl;
            } else {
                cout << "Smallest Index with prefix sum greater than or equal to " << k << " is : " << idx << endl;
            }
        } else {
            cout << "Enter index and new value " << endl;
            int idx, new_val;cin >> idx >> new_val;

            cout << "Update initiated" << endl;
            update(1, 0, n - 1, idx, new_val);
            cout << "Update completed" << endl;
        }
    }
    return 0;
}
