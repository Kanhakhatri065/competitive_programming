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

    list<int> ls;
    int temp;
    for(int i = 0;i < size;i++) {
        cin >> temp;
        ls.push_back(temp);
    }

    ll sereja = 0;
    ll dima = 0;
    int turn = 0;
    while(!ls.empty()) {
        if(ls.front() > ls.back()) {
            temp = ls.front();
            ls.pop_front();
        } else {
            temp = ls.back();
            ls.pop_back();
        }

        if(turn % 2 == 0) {
            sereja += temp;
        } else {
            dima += temp;
        }
        turn++;
    }

    cout << sereja << " " << dima << endl;

    return 0;
}