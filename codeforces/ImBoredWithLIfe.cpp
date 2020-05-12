#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
#define ff first
#define ss second 
#define pp pair
#define ULRED 1000000007
#define MS(x,y) (x-y>0?x-y:y-x) 
#define MX(x,y) x>y?x:y
#define MN(x,y) x>y?y:x
#define MX3(a,b,c) (a>b?(a>c?a:c):(b>c?b:c))

void swapll(ll *a,ll *b){ll tmp=*a;*a=*b;*b=tmp;}
void swapc(char *a,char *b){char tmp=*a;*a=*b;*b=tmp;}
/*----------------------------------------------------------------*/

#define MAX 1000000 
  
ll multiply(ll x, ll res[], ll res_size); 

void factorial(ll n) 
{ 
    ll res[MAX]; 
  
    res[0] = 1; 
    ll res_size = 1; 
  
    for (ll x=2; x<=n; x++) {
        res_size = multiply(x, res, res_size); 
    }
  
    for (ll i=res_size-1; i>=0; i--) {
        cout << res[i]; 
    }
} 
  
ll multiply(ll x, ll res[], ll res_size) 
{ 
    ll carry = 0;   
  
    for (ll i=0; i<res_size; i++) 
    { 
        ll prod = res[i] * x + carry; 
  
        res[i] = prod % 10;   
  
        carry  = prod/10;     
    } 
  
    while (carry) 
    { 
        res[res_size] = carry%10; 
        carry = carry/10; 
        res_size++; 
    } 
    return res_size; 
} 

int main() {
    FAST_IO
    ll a, b;
    cin >> a >> b;

    if(a > b) {
        factorial(b);
    } else {
        factorial(a);
    }
    cout << endl;
    
    return 0;
}