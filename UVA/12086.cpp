#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct FenwickTree {
    int n;
    vector<ll> bit;
    FenwickTree(vector<int> a) {
        n = int(a.size());
        bit.assign(n + 1, 0);
        for(int i = 0;i < n;i++) {
            add(i, a[i]);
        }
    }

    void add(int idx, int val) {
        idx++;
        while(idx <= n) {
            bit[idx] += val;
            idx += (idx & (-idx));
        }
    }

    ll sum(int idx) {
        idx++;
        ll res = 0;
        while(idx > 0) {
            res += bit[idx];
            idx -= (idx & (-idx));
        }

        return res;
    }
    
    ll sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

int main() {
    int n;
    int cases = 0;
    while(true) {
        cases++;
        cin >> n;
        if(!n) break;

        vector<int> a(n);
        for(int i = 0;i < n;i++) cin >> a[i];

        FenwickTree ft(a);

        cout << "Case " << cases << ":" << endl;
        while(true) {
            string type;
            cin >> type;
            if(type == "END") break;

            if(type == "M") {
                int l, r;cin >> l >> r;
                l--, r--;

                ll ans = ft.sum(l, r);
                cout << ans << endl;
            } else {
                int idx, val;
                cin >> idx >> val;
                idx--;
                int adjust = val - a[idx];
                ft.add(idx, adjust);
                a[idx] = val;
            }
        }
    }

    return 0;
}
