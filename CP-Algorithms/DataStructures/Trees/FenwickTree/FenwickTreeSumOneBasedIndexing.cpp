#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
    int n;
    vector<int> bit;

    FenwickTree(int _n) {
        n = _n;
        bit.assign(n + 1, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(int(a.size())) {
        for(int i = 0;i < int(a.size());i++) {
            add(i, a[i]);
        }
    }

    int sum(int idx) {
        int res = 0;
        idx++;
        while(idx > 0) {
            res += bit[idx];
            idx -= (idx & (-idx));
        }

        return res;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        idx++;
        while(idx <= n) {
            bit[idx] += delta;
            idx += (idx & (-idx));
        }
    }
};

int main() {
    cout << "enter the size of the array : " << endl;
    int n;cin >> n;

    cout << "enter the elements of the array : " << endl;
    vector<int> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];

    FenwickTree ft(a);

    cout << "Enter the number of queries : " << endl;
    int q;cin >> q;
    while(q--) {
        cout << "Enter the indices of the range : " << endl;
        int l, r;cin >> l >> r;
        int ans = ft.sum(l, r);
        cout << "Sum in the range (" << l << ", " << r << ") is : " << ans << endl;
    }
    return 0;
}
