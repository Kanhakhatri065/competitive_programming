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
const int MOD = 1e9 + 7;
const int N = 2e4 + 50;

int bit[N + 1], ans[N], n;

void update(int idx, int val) {
    while(idx <= N) {
        bit[idx] += val;
        idx += (idx & (-idx));
    }
}

int query(int idx) {
    int ans = 0;
    while(idx > 0) {
        ans += bit[idx];
        idx -= (idx & (-idx));
    }

    return ans;
}

void solve() {
    cin >> n;
    memset(bit, 0, sizeof(bit));
    memset(ans, 0, sizeof(ans));
    for(int i = 1;i <= n;i++) update(i, 1);
    int m = n, l = 1, s, e;

    for(int i = 1;i <= n;i++) {
        l = (l + i) % m;
        l = !l ? m : l;
        m--;

        s = 1, e = n;
        while(s <= e) {
            int mid = (s + e) >> 1;
            if(query(mid) >= l) e = mid - 1;
            else s = mid + 1;
        }

        ans[s] = i;update(s, -1);
    }

    for(int i = 1;i <= n;i++) cout << ans[i] << " ";
    cout << endl;
}

int main() {
    go();
    int t;cin >> t;
    while(t--) solve();
    return 0;
}
