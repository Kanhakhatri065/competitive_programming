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

    int testcases;
    cin >> testcases;

    int number;
    while(testcases--) {
        cin >> number;

        ll  v[number] = {0};
        for(int i = 0;i < number;i++) {
            cin >> v[i];
        }

        sort(v, v + number);

        ll total =  0;
        for(int i = 0;i < number;i++) {
            if((v[i] - number + 1 + i) >= 0) {
                v[i] = v[i] + i - number + 1;
            } else {
                v[i] = 0;
            }
        }

        for(int i = 0;i < number;i++) {
            total += v[i];
        }

        cout << (total % 1000000007) << endl;
    }

    return 0;
}