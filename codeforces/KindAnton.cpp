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
    ll testcases;
    cin >> testcases;

    ll size;
    while(testcases--) {
        cin >> size;

        vector<ll> a(size, 0);
        for(ll i = 0;i < size;i++) {
            cin >> a[i];
        }

        vector<ll> b(size, 0);
        for(ll i = 0;i < size;i++) {
            cin >> b[i];
        }

        ll positiveones = 0;
        ll negativeones = 0;

        int flag = 0;
        if(a[0] != b[0]) {
            flag = 1;
        } else {
            for(ll i = 0;i < size;i++) {
                if(b[i] > a[i]) {
                    if(positiveones == 0) {
                        flag = 1;
                        break;
                    } else {
                        if(a[i] > 0) {
                            positiveones++;
                        } else if(a[i] < 0) {
                            negativeones++;
                        }
                    }
                } else if(b[i] == a[i]) {
                    if(a[i] > 0) {
                        positiveones++;
                    } else if(a[i] < 0) {
                        negativeones++;
                    }
                } else if(b[i] < a[i]) {
                    if(negativeones == 0) {
                        flag = 1;
                        break;
                    } else {
                        if(a[i] > 0) {
                            positiveones++;
                        } else if(a[i] < 0) {
                            negativeones++;
                        }
                    }
                }
            }
        }

        if(flag == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}