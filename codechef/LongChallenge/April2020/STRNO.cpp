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


ll power(ll a, ll n, ll p) 
{ 
    int res = 1; 
    a = a % p;   
  
    while (n > 0) 
    { 
        if (n & 1) 
            res = (res*a) % p; 
  
        n = n>>1;  
        a = (a*a) % p; 
    } 
    return res; 
} 
  
ll gcd(ll a, ll b) 
{ 
    if(a < b) 
        return gcd(b, a); 
    else if(a%b == 0) 
        return b; 
    else return gcd(b, a%b);   
} 
  
bool isPrime(ll n, int k) { 
   if (n <= 1 || n == 4)  return false; 
   if (n <= 3) return true; 
  
   while (k>0) { 
       int a = 2 + rand()%(n-4);   
  
       if (gcd(n, a) != 1) 
          return false; 
   
       if (power(a, n-1, n) != 1) 
          return false; 
  
       k--; 
    } 
  
    return true; 
} 

ll minPrime(ll number, ll lastPrime) {
    for(ll i = lastPrime + 1;i <= sqrt(number);i++) {
        if(isPrime(i,2)) {
            return i;
        }
    }
    
    return number;
}

ll check(ll x) {
    int temp = x;
    int counter = 0;
    int pr = 2;
    while(temp != 1) {
        if(temp % pr == 0) {
            temp /= pr;
            counter++;
        } else {
            pr = minPrime(temp, pr);
        }
    }
    
    return counter;
}

int main() {
    FAST_IO

    int testcases;
    cin >> testcases;

    ll x, k;
    while(testcases--) {
        cin >> x >> k;

        if(x >= pow(2, k)) {
            if(k == 1) {
                cout << "1" << endl;
            } else if(k == 2) {
                if(isPrime(x,2)) {
                    cout << "0" << endl;
                } else {
                    cout << "1" << endl;
                }
            } else {
                if(isPrime(x,2)) {
                    cout << "0" << endl;
                } else {
                    if(check(x) >= k) {
                        cout << "1" << endl;
                    } else {
                        cout << "0" << endl;
                    }
                }
            }
        } else {
            cout << "0" << endl;
        }
    }

    return 0;
}