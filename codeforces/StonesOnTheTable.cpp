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
    int size;
    cin >> size;

    string str;
    cin >> str;

    int count = 0;
    int flag = 0;
    while(flag == 0) {
        if(str.size() == 1) {
            flag = 1;
            break;
        }
        int temp = -1;
        for(int i = 0;i < str.size() - 1;i++) {
            if(str[i] == str[i + 1]) {
                temp = i;
                break;
            }
        }

        if(temp != -1) {
            str.erase(temp, 1);
            count++;
        } else {
            flag = 1;
        }
    }

    cout << count << endl;

    return 0;
}