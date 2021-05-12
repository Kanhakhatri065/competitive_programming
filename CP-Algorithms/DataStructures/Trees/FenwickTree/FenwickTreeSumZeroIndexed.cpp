#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
    vector<int> bit;
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(int(a.size())) {
        for(int i = 0;i < int(a.size());i++) {
            add(i, a[i]);
        }
    }

    int sum(int r) {
        int res = 0;
        while(r >= 0) {
            res += bit[r];
            r = (r & (r + 1)) - 1;
        }

        return res;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        while(idx < n) {
            bit[idx] += delta;
            idx = idx | (idx + 1);
        }
    }
};

int main() {
    cout << "enter size of the array :" << endl;
    int n;cin >> n;

    cout << "Enter elements of the array : " << endl;
    vector<int> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];

    FenwickTree ft(a);

    cout << "Enter number of queries : " << endl;
    int q;cin >> q;
    while(q--) {
        cout << "Enter left and right indices of the range(0-indexed) : " << endl;
        int l, r;
        cin >> l >> r;

        int ans = ft.sum(l, r);
        cout << "Sum in the range " << l << " to " << r << " is : " << ans << endl;
    }

    return 0;
}
