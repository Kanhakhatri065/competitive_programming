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
    int n, c;
    cin >> n >> c;

    long long int p[n];
    for(int i = 0;i < n;i++) {
        cin >> p[i];
    }

    long long int t[n];
    for(int i = 0;i < n;i++) {
        cin >> t[i];
    }

    long long int score_l = 0;
    long long int time_l = 0;
    for(int i = 0;i < n;i++) {
        time_l += t[i];
        score_l += MX(0, (p[i] - (c * time_l)));;
    }


    long long int score_r = 0;
    long long int time_r = 0;
    for(int i = n - 1;i >= 0;i--) {
        time_r += t[i];
        score_r += MX(0, (p[i] - (c * time_r)));
    }

    if(score_l > score_r) {
        cout << "Limak" << endl;
    } else if(score_l < score_r) {
        cout << "Radewoosh" << endl;
    } else {
        cout << "Tie" << endl;
    }

    return 0;
}