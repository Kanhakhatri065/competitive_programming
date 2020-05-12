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

    int size;
    while(testcases--) {
        cin >> size;

        vector<ll> v(size, 0);
        for(int i = 0;i < size;i++) {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        vector<ll> store;
        int mid = 0;
        if(v.size() % 2 == 0) {
            mid = v.size() / 2 - 1;
        } else {
            mid = v.size() / 2;
        }

        int right = mid + 1;
        int left = mid - 1;

        store.push_back(v[mid]);
        
        for(int i = 0;i < v.size() / 2;i++) {
            if(right < v.size()) {
                store.push_back(v[right]);
                right++;
            }

            if(left >= 0) {
                store.push_back(v[left]);
                left--;
            }
        }

        for(int i = 0;i < store.size();i++) {
            cout << store[i] << " ";
        }
        cout << endl;
    }
    return 0;
}