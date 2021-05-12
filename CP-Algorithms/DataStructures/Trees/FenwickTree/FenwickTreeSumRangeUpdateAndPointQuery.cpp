#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
    int n;
    vector<int> bit;

    FenwickTree(int _n) {
        n = _n + 1;
        bit.assign(n + 1, 0);
    }


    void add(int idx, int val) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += val;
    }

    void range_add(int l, int r, int val) {
        add(l, val);
        add(r + 1, -val);
    }

    int point_query(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    } 
};

int main() {
    cout << "Enter the size of the array : " << endl;
    int n;cin >> n;


    FenwickTree ft(n);

    cout << "Enter the number of queries : " << endl;
    int q;cin >> q;
    while(q--) {
        cout << "enter range and increment value : " << endl;
        int l, r, x;
        cin >> l >> r >> x;
        ft.range_add(l, r, x);

        cout << "Displaying array : " << endl;
        for(int i = 0;i < n;i++) cout << ft.point_query(i) << " ";
        cout << endl;
    }

    return 0;
}
