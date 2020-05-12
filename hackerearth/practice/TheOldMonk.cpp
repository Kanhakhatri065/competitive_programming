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


int main() {
    int testcases;
    cin >> testcases;

    int size;
    for(int i = 0;i < testcases;i++) {
        cin >> size;

        long long int A[size];
        for(int j = 0;j < size;j++) {
            cin >> A[j];
        }

        long long int B[size];
        for(int j = 0;j < size;j++) {
            cin >> B[j];
        }

        int h = 0;
        int z = 0;
        for(int j = 0;j < size;j++) {
            z =0;
            for(int k = j;k < size;k++) {
                if(k >= j && B[k] >= A[j]) {
                    z = k - j;
                } else {
                    z = 0;
                }

                if(z > h) {
                    h = z;
                }

                if(B[k] < A[j]) {
                    break;
                }
            }
        }

        cout << h << endl;
    }

    return 0;
}