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
const int MAX = 1e5 + 5;
ll v[MAX];
ll maxProduct(ll A[], ll n, ll k) { 
    sort(A, A + n); 
  
    ll product = 1; 

    if (A[n - 1] == 0 && (k & 1)) {
        return 0; 
    }
  

    if (A[n - 1] <= 0 && (k & 1)) { 
        for (ll i = n - 1; i >= n - k; i--) 
            product *= A[i]; 
        return product; 
    } 
  
    ll i = 0; 
  
    ll j = n - 1; 
  
    if (k & 1) { 
        product *= A[j]; 
        j--; 
        k--; 
    } 

    k >>= 1; 
  
    for (ll itr = 0; itr < k; itr++) { 
  
        ll left_product = A[i] * A[i + 1]; 
  
        ll right_product = A[j] * A[j - 1]; 
  

        if (left_product > right_product) { 
            product *= left_product; 
            i += 2; 
        } 
        else { 
            product *= right_product; 
            j -= 2; 
        } 
    } 
  
    return product; 
} 

void solve() {
    ll n;
    sc(n);

    forIn(v, n);

    ll ans = maxProduct(v, n, 5);
    pf(ans);
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