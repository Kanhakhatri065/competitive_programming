/*** I came, I saw, I conquered. ***/
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;typedef unsigned long long ull;
/*** Input Output ***/
#define sc(a) cin >> a
#define pf(a) cout << a << endl
/*** Loops ***/
#define for0(num) for(ll i = 0; i < num; i++)
#define forIn(arr, num) for(ll i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
/*** Define Values ***/
#define mod1 1000000007
#define mod2 998244353
#define eps 1e-7
/*** Abbrevations **/
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define mem(name, value) memset(name, value, sizeof(name))
#define pp pair
/*** STLs ***/
typedef vector<ll>vll;typedef set<ll>sll;typedef multiset<ll>msll;
typedef queue<ll>qll;typedef map<ll,ll>mll;typedef pair<ll,ll>pll;
typedef vector<pair<ll,ll>>vpll;
/*** Sorts ***/
#define all(v) (v).begin(), (v).end()
#define srt(v) sort(all(v))
#define srtGreat(v) sort(all(v), greater<ll>())
/*** Bit-Stuff ***/
#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
/*** Some Prints ***/
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
/*** Swapping ***/
void swapll(ll *a,ll *b){ll tmp=*a;*a=*b;*b=tmp;}
void swapc(char *a,char *b){char tmp=*a;*a=*b;*b=tmp;}
/*----------------------------------------------------------------*/

int main() {
    FAST_IO
    ll size;
    sc(size);

    ll count_no_one = 0;

    ll arr[size][size];
    for(ll i = 0;i < size;i++) {
        for(ll j = 0;j < size;j++) {
            sc(arr[i][j]);
            if(arr[i][j] != 1) {
                count_no_one++;
            }
        }
    }

    ll flag = 0;
    for(ll i = 0;i < size;i++) {
        for(ll j = 0;j < size;j++) {
            if(arr[i][j] != 1) {
                int temp_flag = 0;      
                for(ll k = 0;k < size;k++) {
                    if(k != i) {
                        for(ll l = 0;l < size;l++) {
                            if(l != j) {
                                if(arr[k][j] + arr[i][l] == arr[i][j]) {
                                    temp_flag = 1;
                                    break;
                                }
                            }

                        }

                        if(temp_flag == 1) {
                            break;
                        }
                    }
                }

                if(temp_flag == 1) {
                    flag++;            
                }
            }
        }
    }

    if(flag == count_no_one) {
        yes;
    } else {
        no;
    }

    return 0;
}