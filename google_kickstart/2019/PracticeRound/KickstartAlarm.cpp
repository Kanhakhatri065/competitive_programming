/*
    I love the sound you make when you shut up.
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
/*-------typedefs------*/
template<class T> using ordered_set = tree<T, null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update> ;
using ll = long long;
using pi = pair<int, int>;
/*-----in and out--------*/
#define pf(a) cout << a << endl
#define forIn(arr, num) for(int i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(int i = 0; i < int(ans.size()); i++) cout << ans[i] << (i + 1 < int(ans.size()) ? ' ' : '\n');
/*---useful defines------*/
#define sz(x) (int)(x).size()
#define pb push_back
#define mem(a, b) memset(a,(b), sizeof(a))
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
/*----- the binary answer of life-----*/
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
/*---checking and pushing-----*/
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
/*---- FAST I/O and file read ---*/
void go() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
}
/*-------- test-case stuff--------------*/
#define ssolve solve();
#define msolve int T;cin >> T;while(T--) {solve();}
#define mcsolve int T;cin >> T;for(int tt = 1;tt <= T;tt++) {cout << "Case #" << tt << ": ";solve();}
/*-------- movement in a 2D array ------*/
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
/*----------------------------------------------------------------*/
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
const int MAX = 1e6 + 4;
/*-------------- Push your limits here ---------------------------*/
ll a[N], px[N];
ll pow_mod(ll x, ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) res = (1LL * res * x) % MOD;
        x = (1LL * x * x) % MOD;
        y >>= 1;
    }

    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;

    ll x1, y1, c, d, e1, e2, f;
    cin >> x1 >> y1 >> c >> d >> e1 >> e2 >> f;

    ll x, y;
    a[1] = (x1 + y1) % f;
    for(int i = 2;i <= n;i++) {
        x = (c * x1 + d * y1 + e1) % f;
        y = (d * x1 + c * y1 + e2) % f;
        a[i] = (x + y) % f;
        x1 = x, y1 = y;
    }

    ll ans = 0;
    ll la = k;
    for(int i = 2;i <= n + 1;i++) {
        ans = (ans + 1LL * la * (ll)(n + 2 - i) % MOD * a[i - 1] % MOD) % MOD;
        ll t = (pow_mod(i, k + 1) - 1) * pow_mod(i - 1, MOD - 2) % MOD;
        t--;
        if(t < 0) t += MOD;
        la = (la + t) % MOD;
    }

    pf(ans);
}

int main() {
    go();
    mcsolve
    return 0;
}
