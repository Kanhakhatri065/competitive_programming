/*
    I love the sound you make when you shut up.
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
/*----typedefs--------*/
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
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
/*-------- movement in a 2D array ------*/
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
/*--------test-case stuff---------------*/
#define ssolve solve();
#define msolve int t;cin >> t;while(t--) {solve();}
#define mcsolve int t;cin >> t;for(int tt = 1;tt <= t;tt++) {cout << "Case #" << tt << ": ";solve();}
/*----------------------------------------------------------------*/
const int MOD = 1e9 + 7;
const int N = 300500;
/*-------------- Push your limits here ---------------------------*/
ll fact[N];
ll invFact[N];

ll fast_pow(ll a, ll p) {
    ll res = 1;
    while(p) {
        if(p & 1) {
            res = (res * a) % MOD;
            p--;
        } else {
            a = (a * a) % MOD;
            p /= 2;
        }
    }

    return res;
}

void initfact() {
    fact[0] = invFact[0] = 1;
    for(int i = 1;i < N;i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = fast_pow(fact[i], MOD - 2);
    }
}

ll choose(int n, int k) {
    if(k > n) return 0; 
    return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> v(n);
    forIn(v, n);

    sort(all(v));

    ll ans = 0;
    for(int i = 0;i < n;i++) {
        int l = i + 1;
        int r = upper_bound(all(v), v[i] + k) - v.begin();
        ans = (ans + choose(r - l, m - 1)) % MOD;
    }

    pf(ans);
}

int main() {
    go();
    initfact();
    msolve
    return 0;
}
