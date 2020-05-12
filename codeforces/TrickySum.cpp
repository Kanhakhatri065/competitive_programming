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

long long int find_n(long long int number) {
    long long int count = 0;
    long long int temp = number;
    while(temp != 0) {
        temp /= 2;
        count++;
    }

    return count;
}

int main() {
    FAST_IO

    int testcases;
    cin >> testcases;

    long long int number;
    while(testcases--) {
        cin >> number;

        long long int sum_natural_numbers = (number * (number + 1)) / 2;

        long long int nth = find_n(number);

        long long int sum_2_power = pow(2, nth) - 1;

        long long int output = sum_natural_numbers - (2 * sum_2_power);

        cout << output << endl;
    }

    return 0;
}