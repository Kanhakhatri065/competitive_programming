#include <bits/stdc++.h>
using namespace std;

//memory efficient seg treex
const int N = 1e5 + 5;
int n;
int t[2 * N];

void build(int a[]) {
    for(int i = 0;i < n;i++) t[n + i] = a[i];
    for(int i = n - 1;i >= 0;i--) t[i] = t[i << 1] + t[i << 1 | 1];
}

void modify(int p, int val) {
    for(t[p += n] = val;p > 1;p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
}

// for queries [l, r)
int query(int l, int r) {
    int res = 0;
    for(l += n, r += n;l < r;l >>= 1, r >>= 1) {
        if(l & 1) res += t[l++];
        if(r & 1) res += t[--r];
    }

    return res;
}

int main() {
    cout << "Enter the size of the array : " << endl;
    cin >> n;

    int a[n];
    cout << "Enter the elements of the array : " << endl;
    for(int i = 0;i < n;i++) cin >> a[i];

    cout << "Build initiated" << endl;
    build(a);
    cout << "Build completed" << endl;

    cout << "Enter the number of queries : " << endl;
    int q;
    cin >> q;
    while(q--) {
        cout << "Enter the type of query : \n1. Sum\n2. Update" << endl;
        int type;cin >> type;
        if(type == 1) {
            cout << "Enter the range for sum query : " << endl;
            int l, r;cin >> l >> r;
            int ans = query(l, r);

            cout << "Sum of elements in the range [" << l << ", " << r << ") : " << ans << endl; 
        } else {
            cout << "Input index and new value : " << endl;
            int idx, new_val;
            cin >> idx >> new_val;

            cout << "Update initiated" << endl;
            modify(idx, new_val);
            cout << "Update completed" << endl;
        }
    }
    return 0;
}