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
#define mod 1000000007
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
/*** comparators ***/
#define MX(x,y) x>y?x:y
#define MN(x,y) x>y?y:x
/*----------------------------------------------------------------*/

int main() {
    FAST_IO
    ll n;
    sc(n);

    vll v(n, 0);
    forIn(v, n);

    ll m;
    sc(m);

    ll arr[m][2];
    for0(m) {
        sc(arr[i][0]);
        sc(arr[i][1]);
        arr[i][0]--;
    }

    ll cable = 0;
    ll shot = 0;
    if(v.size() > 1) {
        
        for0(m) {
            cable = arr[i][0];
            shot = arr[i][1];

            if(cable > 0 && cable < n - 1) {
                v[cable - 1] += shot - 1;
                v[cable + 1] += v[cable] - shot;
                v[cable] = 0;
            }

            if(cable == 0) {
                v[cable + 1] += v[cable] - shot;
                v[cable] = 0;
            }

            if(cable == n - 1) {
                v[cable -1] += shot - 1;
                v[cable] = 0;
            }
        }
    } else {
        for0(m) {
            cable = arr[i][0];
            v[cable] = 0;
        }
    }

    for(ll i = 0;i < n;i++) {
        pf(v[i]);
    }

    return 0;
}