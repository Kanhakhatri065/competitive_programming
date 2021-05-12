#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;// limit of the array size
int n;// array size
int t[2 * N];

void build() { //build the tree
    for(int i = n - 1;i > 0;i--) {
        t[i] = t[i << 1] + t[i << 1 | 1];
    }
}

void modify(int p, int new_val) { // set value at position p
    for(t[p + n] = new_val;p > 1;p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
}

int query(int l, int r) {// sum on interval [l to r)
    int res = 0;
    for(l += n, r += n;l < r;l >>= 1, r >>= 1) {
        if(l & 1) res += t[l++];
        if(r & 1) res += t[--r];
    }

    return res;
}

int main() {
    cin >> n;

    for(int i = 0;i < n;i++) {
        int x;
        cin >> x;

        t[n + i] = x;
    }

    build();
    cout << "0 to 4 : " << query(0, 5) << endl;
    cout << "0 to 3 : " << query(0, 4) << endl;
    cout << "0 to 0 : " << query(0, 1) << endl;
    cout << "modify the value at 0 to 3" << endl;
    modify(0, 3);
    cout << "0 to 0 : " << query(0, 1) << endl;
    cout << "0 to 4 : " << query(0, 4 + 1) << endl;
    cout << "0 to 3 : " << query(0, 3 + 1) << endl;

    return 0;
}
