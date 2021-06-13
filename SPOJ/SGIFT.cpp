#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pf(a) cout << a << endl
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for(int i = 0;i < n;i++) scanf("%d", &a[i]);

    sort(all(a));
    map<int, vector<int>> idx_store;
    for(int i = 0;i < n;i++) idx_store[a[i]].pb(i);

    vector<ll> ft(n + 1);
    auto add = [&] (int idx, int val) {
        idx++;
        while(idx <= n) {
            ft[idx] += val;
            idx += (idx & (-idx));
        }
    };

    auto get = [&] (int idx) -> ll {
        idx++;
        ll res = 0;
        while(idx > 0) {
            res += ft[idx];
            idx -= (idx & (-idx));
        }

        return res;
    };

    for(int i = 0;i < n;i++) add(i, a[i]);

    int q;scanf("%d", &q);
    while(q--) {
        int l, r;scanf("%d%d", &l, &r);

        if(l > idx_store.rbegin()->ff) {
            printf("0\n");
            continue;
        }

        if(r < idx_store.begin()->ff) {
            printf("0\n");
            continue;
        }

        if(l < idx_store.begin()->ff) {
            l = 0;
        } else {
            auto itl = idx_store.lower_bound(l);
            l = itl->ss.front();
        }

        if(r > idx_store.rbegin()->ff) {
            r = n - 1;
        } else {
            auto itr = idx_store.lower_bound(r);
            if(itr->ff > r) {
                itr--;
            }

            r = itr->ss.back();
        }

        ll ans = get(r) - get(l - 1);
        printf("%lld\n", ans);
    }
}

int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}