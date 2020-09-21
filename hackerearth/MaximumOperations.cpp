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
ll xnor(ll a, ll b) 
{ 
    // Make sure a is larger 
    if (a < b) 
        swap(a, b);  
  
    if (a == 0 && b == 0)  
        return 1;  
  
    int a_rem = 0; // for last bit of a 
    int b_rem = 0; // for last bit of b 
  
    // counter for count bit  
    // and set bit  in xnornum 
    int count = 0;  
  
    // to make new xnor number 
    int xnornum = 0; 
  
    // for set bits in new xnor number 
    while (a)  
    { 
        // get last bit of a 
        a_rem = a & 1;  
  
        // get last bit of b 
        b_rem = b & 1;  
  
        // Check if current two 
        // bits are same 
        if (a_rem == b_rem)         
            xnornum |= (1 << count); 
          
        // counter for count bit 
        count++;  
        a = a >> 1; 
        b = b >> 1;  
    } 
    return xnornum; 
} 

void solve() {
    ll a, b, n;
    cin >> a >> b >> n;

    ll x[3];
    x[0] = a, x[1] = b;
    x[2] = x[0] ^ x[1];

    ll xn[3];
    xn[0] = a, xn[1] = b;
    xn[2] = xnor(xn[0], xn[1]);

    n--;

    pf(max(x[n % 3], xn[n % 3]));
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