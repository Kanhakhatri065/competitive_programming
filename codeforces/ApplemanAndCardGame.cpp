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

    ll size, choose;
    cin >> size >> choose;

    string str;
    cin >> str;

    map<char, ll> m;
    for(ll i = 0;i < str.size();i++) {
        m[str[i]]++;
    }

    map<char, ll>::iterator it;
    
    vector<ll> store;
    for(it = m.begin();it != m.end();++it) {
        store.push_back(it->second);
    }

    sort(store.begin(), store.end(), greater<ll>());

    long long int total = 0;
    
    ll i = 0;
    while(choose > 0 && i < store.size()) {
        if(store[i] > choose) {
            total += (choose * choose);
            break;
        } else {
            choose -= store[i];
            total += (store[i] * store[i]);
        }
        i++;
    }



    cout << total << endl;

    return 0;
}