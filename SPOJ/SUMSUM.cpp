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
void go() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
}

const int N = 1e5 + 5;
const int K = 29;

int a[N], ft[K][N];

void add(int *ft, int pos, int val) {
    for(;pos < N;pos += (pos & (-pos))) {
        ft[pos] += val;
    }
}

int get(int *ft, int pos) {
    int s = 0;
    for(;pos > 0;pos -= (pos & (-pos))) {
        s += ft[pos];
    }

    return s;
}

int get(int *ft, int l, int r) {
    return get(ft, r) - get(ft, l - 1);
}

void solve() {
    int n, q;cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 0;i < K;i++) {
        for(int j = 1;j <= n;j++) {
            if(a[j] & (1 << i)) add(ft[i], j, 1);
        }
    }

    while(q--) {
        int type;cin >> type;
        if(type == 1) {
            int val, idx;cin >> val >> idx;
            for(int i = 0;i < K;i++) {
                if(a[idx] & (1 << i)) {
                    add(ft[i], idx, -1);
                }
            }

            a[idx] = val;
            for(int i = 0;i < K;i++) {
                if(a[idx] & (1 << i)) {
                    add(ft[i], idx, 1);
                }
            }
        } else {
            string bin_op;cin >> bin_op;
            int l, r;cin >> l >> r;
            ll res = 0;
            for(int i = 0;i < K;i++) {
                int ones = get(ft[i], l, r);
                int zeros = r - l + 1 - ones;
                if(bin_op == "XOR") {
                    res += 1LL * (1LL << i) * ones * zeros;
                } else if(bin_op == "OR") {
                    res += 1LL * (1LL << i) * ones * zeros + 1LL * (1LL << i) * ones * (ones - 1) / 2;
                } else {
                    res += 1LL * (1LL << i) * ones * (ones - 1) / 2;
                }
            }

            pf(res);
        }
    }
}

int main() {
    go();
    int t = 1;
    while(t--) solve();
    return 0;
}