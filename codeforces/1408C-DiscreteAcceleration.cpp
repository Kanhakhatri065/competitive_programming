/*** I came, I saw, I conquered. ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef unsigned long long ull;
#define sc(a) cin >> a
#define pf(a) cout << a << endl
#define forIn(arr, num) for(ll i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
#define mod 1000000007
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
void go() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
/*----------------------------------------------------------------*/
void solve() {
    int n, l;
    cin >> n >> l;

    vector<int> v(n);
    forIn(v, n);

    double total = 0;
    double x0 = 0; int v0 = 1;
    double x1 = l; int v1 = 1;
    int low = 0, high = n - 1;

    while(low <= high) {
        double t0 = (v[low] - x0) / v0;
        double t1 = (x1 - v[high]) / v1;

        if(t0 <= t1) {
            total += t0;
            x0 = v[low];
            x1 -= v1 * t0;
            low++;
            v0++;
        } else {
            total += t1;
            x1 = v[high];
            x0 += v0 * t1;
            high--;
            v1++;
        }
    }

    total += (x1 - x0) / (v0 + v1);
    cout << fixed << setprecision(15) << total << endl;
}

int main() {
    go();
    int t;
    sc(t);

    while(t--) {
        solve();
    }

    return 0;
}