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
#ifdef LOCAL
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
}
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

map<pair<int, int>, int> cache;

void dec(int pos,int l, int r) {
    cache[{l, r}]--;
    if(l != r) {
        int m = (l + r) >> 1;
        if(pos <= m) {
            dec(pos, l, m);
        } else {
            dec(pos, m + 1, r);
        }
    }
}

void solve() {
    int n, t;
    cin >> n >> t;
    while(t--) {
        int k;
        cin >> k;
        int l = 0, r = n - 1;
        while(l != r) {
            int m = (l + r) >> 1;
            pair<int, int> range = {l, m};
            if(cache.count(range) == 0) {
                cout << "? " << (range.ff + 1) << " " << (range.ss + 1) << endl;
                cin >> cache[range];
                cache[range] = range.ss - range.ff + 1 - cache[range];
            }

            int val = cache[range];
            if(k <= val) {
                r = m;
            } else {
                k -= val;
                l = m + 1;
            }
        }

        cout << "! " << (l + 1) << endl;
        dec(l, 0, n - 1);
    }
}

int main() {
    //go();
    int t;t = 1;
    while(t--) solve();
    return 0;
}