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

int main() {
    FAST_IO

    ll n, a, b;
    cin >> n >> a >> b;
    
    int flag = 0;
    if(n % 2 != 0 && a % 2 == 0 && b % 2 == 0) {
        int flag = 1;
    }

    int flag1 = 0;

    if(flag == 0) {
        if(n % a == 0) {
            cout << "YES" << endl;
            cout << (n / a) << " " << "0" << endl;
            flag1 = 1;
        } else if(n % b == 0){
            cout << "YES" << endl;
            cout << "0" << " " << (n / b) << endl;
            flag1 = 1;
        } else {
            if(a >= b) {
                for(ll i = 1;i <= (n / a);i++) {
                    if((n - (i * a)) % b == 0) {
                        cout << "YES" << endl;
                        cout << i << " " << ((n - (i * a)) / b) << endl;
                        flag1 = 1;
                        break;
                    }
                }
            } else {
                for(ll i = 1;i <= (n / b);i++) {
                    if((n - (i * b)) % a == 0) {
                        cout << "YES" << endl;
                        cout << ((n - (i * b)) / a) << " " << i << endl;
                        flag1 = 1;
                        break;
                    }
                }
            }
        }
    }

    if(flag == 0 && flag1 == 0) {
        cout << "NO" << endl;
    } else if(flag == 1 && flag1 == 0) {
        cout << "NO" << endl;
    }
    return 0;
}