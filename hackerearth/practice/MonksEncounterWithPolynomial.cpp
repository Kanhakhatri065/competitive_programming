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
#define MX3(a,b,c) (a>b?(a>c?a:c):(b>c?b:c))

void swapll(ll *a,ll *b){ll tmp=*a;*a=*b;*b=tmp;}
void swapc(char *a,char *b){char tmp=*a;*a=*b;*b=tmp;}
/*----------------------------------------------------------------*/
/*
int main() {
    FAST_IO

    ll testcases;
    cin >> testcases;

    ll a, b, c, k;
    while(testcases--) {
        cin >> a >> b >> c >> k;

        ll number = 0;
        while(true) {
            ll equation = (a * number * number) + (b * number) + c - k;
            if(equation >= 0) {
                break;
            }
            number++;
        }

        cout << number << endl;
    }

    return 0;
}
*/

int main() {
    FAST_IO

    ll testcases;
    cin >> testcases;

    ll a, b, c, k;
    while(testcases--) {
        cin >> a >> b >> c >> k;
        c -= k;

        ll ans = 0;
        if(((b * b) - (4 * a * c)) <= 0 || c >= 0) {
            ans = 0;
        } else {
            ans = ceil((sqrt((b * b) - (4 * a * c)) - b) / (2 * a));
        }
            cout << ans << endl;
    }
    return 0;
}