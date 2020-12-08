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
/*---- FAST I/O and file read ---*/
void go() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
}
/*--------test-case stuff---------------*/
#define ssolve solve();
#define msolve int t;cin >> t;while(t--) {solve();}
#define mcsolve int t;cin >> t;for(int tt = 1;tt <= t;tt++) {cout << "Case #" << tt << ": ";solve();}
/*----------------------------------------------------------------*/
const ll MOD = 998244353;
/*-------------- Push your limits here ---------------------------*/
ll modInverse(ll a, ll m) { 
    int m0 = m; 
    int y = 0, x = 1; 
  
    if (m == 1) return 0; 
  
    while (a > 1) { 
        int q = a / m; 
        int t = m; 
  
        m = a % m, a = t; 
        t = y; 
  
        y = x - q * y; 
        x = t; 
    } 
  
    if (x < 0) x += m0; 
  
    return x; 
} 
 
void solve() {
    int n;
    cin >> n;

    ll a = (1LL * n * 22) % MOD, b = 7;
    ll b_inverse = modInverse(b, MOD);

    ll ans = (a * b_inverse) % MOD;
    pf(ans);
}

int main() {
    go();
    ssolve
    return 0;
}
