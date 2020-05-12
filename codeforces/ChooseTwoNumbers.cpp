#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;

/*** Input Output ***/
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sc1(a) scanf("%lld",&a)
#define sc2(a,b) scanf("%lld %lld",&a,&b)
#define sc3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)

#define pf1(a) printf("%d\n",a)
#define pf2(a,b) printf("%d %d\n",a,b)
#define pfll1(a) printf("%lld\n",a)
#define pfll2(a,b) printf("%lld %lld\n",a,b)

/*** Loops ***/
#define foR0(num) for(ll i = 0; i < num; i++)
#define foR1(num) for(ll i = 1; i <= num; i++)
#define foRev(num) for(ll i = num - 1; i >= 0; i--)
#define forIn(arr, num) for(ll i = 0; i < num; i++) sc1(arr[i]);
#define forIn1(arr, num) for(ll i = 1; i <= num; i++) sc1(arr[i]);
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
#define apnt(arr, num) for(ll i = 0; i < num; i++) cout << arr[i] << (i + 1 < num ? ' ' : '\n');


/*** Define Values ***/
#define mx 200005
#define mod 1000000007
#define PI acos(-1.0)
#define eps 1e-7
#define size1 1000010

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define mem(name, value) memset(name, value, sizeof(name))
#define pp pair

/*** STLs ***/
typedef vector <ll> vll;
typedef set <ll> sll;
typedef multiset <ll> msll;
typedef queue <ll> qll;
typedef map <ll, ll> mll;
typedef pair <ll, ll> pll;
typedef vector <pair <ll , ll> > vpll;

/*** Sorts ***/
#define all(v) (v).begin(), (v).end()
#define rev(v) reverse(all(v))
#define srt(v) sort(all(v))
#define srtGreat(v) sort(all(v), greater<ll>())


#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
#define ULRED 1000000007
#define MS(x,y) (x-y>0?x-y:y-x)
#define MX(x,y) x>y?x:y
#define MN(x,y) x>y?y:x
#define MX3(a,b,c) (a>b?(a>c?a:c):(b>c?b:c))

/*** Some Prints ***/
#define no cout << "NO" << endl
#define yes cout << "YES" << endl

void swapll(ll *a,ll *b){ll tmp=*a;*a=*b;*b=tmp;}
void swapc(char *a,char *b){char tmp=*a;*a=*b;*b=tmp;}
/*----------------------------------------------------------------*/

int main() {
    FAST_IO
    int n;
    sci1(n);

    vll v1(n, 0);
    foR0(n) {
        sc1(v1[i]);
    }

    int m;
    sci1(m);
    vll v2(m, 0);
    foR0(m) {
        sc1(v2[i]);
    }

    srtGreat(v1);
    srtGreat(v2);

    cout << v1[0] << " " << v2[0] << endl;

    return 0;
}














