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

    int size;
    cin >> size;

    vector<ll> arr;
    ll temp;
    for(int j = 0;j < size;j++) {
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    ll queries;
    cin >> queries;

    int type;
    ll number;
    for(ll i = 0;i < queries;i++) {
        cin >> type >> number;

        int count = 0;
        if(type == 0) {
            count = lower_bound(arr.begin(), arr.end(), number) - arr.begin();
        } else {
            count = upper_bound(arr.begin(), arr.end(), number) - arr.begin();
        }

        cout << (size - count) << endl;
    }

    return 0;
}