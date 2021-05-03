#include <bits/stdc++.h>

using namespace std;

struct FenwickTree {
    vector<int> bit;
    int n;

    FenwickTree(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(int(a.size())) {
        for(int i = 0;i < int(a.size());i++) {
            add(i, a[i]);
        }
    }

    void add(int idx, int val) {
        idx++;
        while(idx < n) {
            bit[idx] += val;
            idx += idx & (-idx);
        }
    }

    void range_add(int l, int r, int val) {
        add(l, val);
        add(r + 1, -val);
    }

    int point_query(int idx) {
        int ret = 0;
        idx++;

        while(idx > 0) {
            ret += bit[idx];
            idx -= idx & (-idx);
        }

        return ret;
    }
};

int main() {
    vector<int> a({1, 2, 3, 4, 5});

    FenwickTree fenwicktree(a);

    cout << "Value at idx 3 : " << fenwicktree.point_query(3) - fenwicktree.point_query(2) << endl;

    cout << "Update val by 2 from idx 0 to 4" << endl;
    fenwicktree.range_add(0, 4, 2);

    cout << "Value at idx 3 : " << fenwicktree.point_query(3) - fenwicktree.point_query(2) << endl;

    return 0;
}
