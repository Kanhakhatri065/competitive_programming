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

        vector<ll> v(size, 0);
        for(ll i = 0;i < size;i++) {
            cin >> v[i];
        }

        map<ll, ll> m;

        ll sum = 0;
        for(ll i = 0;i < size;i++) {
            sum += v[i];
        }

        ll sum_start = 0;
        ll condition1 = 0;
        ll condition2 = 0;

        for(ll i = 0;i < size - 1;i++) {
            sum_start += v[i];
            sum -= v[i];
            condition1 = (((i + 1) * (i + 2)) / 2);
            condition2 = (((size - i - 1) * (size - i)) / 2);

            if(sum_start == condition1 && sum == condition2) {
                m[i + 1] = (size - i - 1);
            }
        }

        cout << m.size() << endl;
        if(m.size() != 0) {
            map<ll, ll>::iterator it;
            for(it = m.begin();it != m.end();++it) {
                cout << it->ff << " " << it->ss << endl;
            }
        }
    }
    return 0;
}