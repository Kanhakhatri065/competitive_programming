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

    int sum(int idx) {
        int ret = 0;
        idx++;

        while(idx > 0) {
            ret += bit[idx];
            idx -= idx & (-idx);
        }

        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        idx++;
        while(idx < n) {
            bit[idx] += delta;
            idx += idx & (-idx);
        }
    }
};

int main() {
    vector<int> a({1, 2, 3, 4, 5});

    FenwickTree fenwicktree(a);

    cout << "Sum from idx 0 to 4 : " << fenwicktree.sum(0, 4) << endl;

    return 0;
}
