#include <bits/stdc++.h>
using namespace std;

int main() {
    //Input data
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];

    int len = (int) sqrt(n + 0.0) + 1;
    vector<int> b(len);
    for(int i = 0;i < n;i++) b[i / len] += a[i];

    int q;
    cin >> q;
    while(q--) {
        int l, r;cin >> l >> r;
        int blockL = l / len, blockR = r / len;
        
        int sum = 0;
        if(blockL == blockR) {
            for(int i = l;i <= r;i++) sum += a[i];
        } else {
            for(int i = l, end = ((blockL + 1) * len - 1);i <= end;i++) sum += a[i];
            for(int i = blockL + 1;i <= blockR - 1;i++) sum += b[i];
            for(int i = blockR * len;i <= r;i++) sum += a[i];
        }
        cout << sum << endl;
    }
    return 0;
}
