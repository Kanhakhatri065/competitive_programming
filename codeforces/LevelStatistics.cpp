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
    int testcases;
    cin >> testcases;

    int n;
    while(testcases--) {
        cin >> n;
        
        int arr[n][2];
        for(int i = 0;i < n;i++) {
            cin >> arr[i][0] >> arr[i][1];
        }

        int flag = 0;

        if(arr[0][0] < arr[0][1]) {
            flag = 1;
        }

        int last_play = arr[0][0];
        int last_clear = arr[0][1];
        for(int i = 1;i < n;i++) {
            if(arr[i][0] >= last_play && arr[i][1] >= last_clear) {
                if(arr[i][0] - last_play < arr[i][1] - last_clear) {
                    flag = 1;
                } else {
                    last_play = arr[i][0];
                    last_clear = arr[i][1];
                }
            } else {
                flag = 1;
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