#include <bits/stdc++.h>
using namespace std;

struct FenwickTreeMin {
    vector<int> bit;
    int n;
    const int INF = 1e9;

    FenwickTreeMin(int n) {
        this->n = n;
        bit.assign(n, INF);
    }

    FenwickTreeMin(vector<int> a) : FenwickTreeMin(int(a.size())) {
        for(int i = 0;i < int(a.size());i++) {
            update(i, a[i]);
        }
    }

    int getmin(int r) {
        int res = INF;
        while(r >= 0) {
            res = min(res, bit[r]);
            r = (r & (r + 1)) - 1;
        }

        return res;
    }

    void update(int idx, int val) {
        while(idx < n) {
            bit[idx] = min(bit[idx], val);
            idx =   idx | (idx + 1);
        }
    }
};

int main() {
    cout << "Enter the size of the array : " << endl;
    int n;cin >> n;

    cout << "Enter the elements of the array : " << endl;
    vector<int> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];

    FenwickTreeMin ft(a);

    cout << "Enter the number of queries : " << endl;
    int q;cin >> q;
    while(q--) {
        cout << "Enter right range of the query to ask min(0, r) : " << endl;
        int r;cin >> r;

        int ans = ft.getmin(r);
        cout << "Minimum in the range of (0, " << r << ")" << " is : " << ans << endl;
    }

    return 0;
}
