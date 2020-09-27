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
typedef int64_t badaint;
const badaint INF = 1e17;
inline badaint mul(badaint a, badaint b) {
    return (INF / a > b) ? a * b : INF;
}

inline badaint add(badaint a, badaint b) {
    return (a + b >= INF ? INF : a + b);
}

void solve() {
    int n;
    sc(n);

    vector<int> v(n);
    forIn(v, n);

    sort(all(v));

    if(n <= 2) {
        pf(v[0] - 1);
    } else {
        badaint ans = accumulate(all(v), 0LL) - n;

        for(int x = 1;;x++) {
            badaint curPow = 1, curCost = 0;
            for(int i = 0;i < n;i++) {
                curCost = add(curCost, abs(v[i] - curPow));
                curPow = mul(curPow, x);
            }

            if(curPow == INF || curPow / x > ans + v.back()) {
                break;
            }

            ans = min(ans, curCost);
        }

        pf(ans);
    }
}

int main() {
    go();
    solve();
    return 0;
}