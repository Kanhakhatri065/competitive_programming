#include <bits/stdc++.h>
using namespace std;

struct FenwickTree2D {
    int n, m;
    vector<vector<int>> bit;

    FenwickTree2D(vector<vector<int>> a) {
        n = int(a.size()), m = int(a[0].size());
        bit.assign(n, vector<int>(m));

        for(int i = 0;i < int(a.size());i++) {
            for(int j = 0;j < int(a[0].size());j++) {
                add(i, j, a[i][j]);
            }
        }
    }

    int sum(int x, int y) {
        int res = 0;
        for(int i = x;i >= 0;i = (i & (i + 1)) - 1) {
            for(int j = y;j >= 0;j = (j & (j + 1)) - 1) {
                res += bit[i][j];
            }
        }

        return res;
    }

    void add(int x, int y, int delta) {
        for(int i = x;i < n;i = i | (i + 1)) {
            for(int j = y;j < n;j = j | (j + 1)) {
                bit[i][j] += delta;
            }
        }
    }
};

int main() {
    cout << "Enter the dimensions of the array : " << endl;
    int n, m;cin >> n >> m;

    cout << "Enter the elements of the array : " << endl;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) cin >> a[i][j];

    FenwickTree2D ft(a);

    cout << "Enter the num of queries : " << endl;
    int q;cin >> q;
    while(q--) {
        cout << "Enter the bottom right index of the submatrix : " << endl;
        int x, y;cin >> x >> y;
        int ans = ft.sum(x, y);

        cout << "Sum of elements in the submatrix (0, 0) to (" << x << ", " << y << ")";
        cout << " is : " << ans << endl;
    }

    return 0;
}
