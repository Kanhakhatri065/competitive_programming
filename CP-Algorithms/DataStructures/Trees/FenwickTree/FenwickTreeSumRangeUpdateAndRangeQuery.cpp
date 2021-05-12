#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> b1, b2;

void init(int _n) {
    n = _n;
    b1.assign(n + 1, 0);
    b2.assign(n + 1, 0);
}
//use 1-indexed when passing idx
void add(int type, int idx, int x) {
    while(idx <= n) {
        if(type == 1) b1[idx] += x;
        else b2[idx] += x;
        idx += (idx & (-idx));
    }
}

void range_add(int l, int r, int x) {
    add(1, l, x);
    add(1, r + 1, -x);
    add(2, l, x * (l - 1));
    add(2, r + 1, -x * r);
}

int sum(int type, int idx) {
    int res = 0;
    while(idx > 0) {
        if(type == 1) res += b1[idx];
        else res += b2[idx];
        idx -= (idx & (-idx));
    }

    return res;
}

int prefix_sum(int idx) {
    return sum(1, idx) * (idx) - sum(2, idx);
}
//use 1-indexed when passing l and r
int range_sum(int l, int r) {
    return prefix_sum(r) - prefix_sum(l - 1);
}

int main() {
    cout << "Enter the size of array : " << endl;
    int num;cin >> num;
    init(num);

    cout << "Enter number of queries : " << endl;
    int q;cin >> q;
    while(q--) {
        cout << "Enter type of query :\n1. Range Update\n2.Range Query" << endl;
        int type;cin >> type;
        if(type == 1) {
            cout << "Enter range(1-indexed) and increment value : " << endl;
            int l, r, x;cin >> l >> r >> x;
            range_add(l, r, x);
        } else {
            cout << "Enter range(1-indexed) to find the sum : " << endl;
            int l, r;cin >> l >> r;
            int ans = range_sum(l, r);
            cout << "Sum of elements in the range (" << l << ", " << r << ") is : " << ans << endl;
        }
    }
    return 0;
}
