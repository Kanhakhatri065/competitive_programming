#include <bits/stdc++.h>

using namespace std;

struct FenwickTree {
    vector<vector<int>> bit;
    int n, m;

    FenwickTree(int n, int m) {
        this->n = n;
        this->m = m;

        bit.assign(n, vector<int>(m, 0));
    }

    FenwickTree(vector<vector<int>> a, int n, int m) : FenwickTree(n, m) {
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                add(i, j, a[i][j]);
            }
        }
    }

    int sum(int x, int y) {
        int ret = 0;
        for(int i = x;i >= 0;i = (i & (i + 1)) - 1) {
            for(int j = y;j >= 0;j = (j & (j + 1)) - 1) {
                ret += bit[i][j];
            }
        }

        return ret;
    }

    void add(int x, int y, int delta) {
        for(int i = x;i < n;i = i | (i + 1)) {
            for(int j = y;j < m;j = j | (j + 1)) {
                bit[i][j] += delta;
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m, 0));
    for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) cin >> a[i][j];

    FenwickTree fenwicktree(a, n, m);

    cout << "Sum from (0, 0) to (3, 3) : " << fenwicktree.sum(3, 3) << endl;

    return 0;
}
