/*** I came, I saw, I conquered. ***/
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;typedef unsigned long long ull;
/*** Input Output ***/
#define sc(a) cin >> a
#define pf(a) cout << a << endl
/*** Loops ***/
#define f(i, p, num) for(ll i = p; i < num; i++)
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
void solve() {
    ll a, b, c, d;
    sc(b);
    sc(c);
    sc(d);
    a=3;
    if(b==2){
      if((c+d)%3==0)
        cout<<"YES\n";
      else
        cout<<"NO\n";
    }
    else{
      long long e=(c+d)%10,f=c+d+e;
      if(e!=0&&e!=5){
        while(e!=2&&a<b){
          e=(2*e)%10;
          f+=e;
          ++a;
        }
        if(a<b){
          long long g=b-a;
          long long h=g%4,i=g/4;
          f+=i*20;
          if(h==3)
            f+=18;
          else if(h==2)
            f+=12;
          else if(h==1)
            f+=4;
        }
        if(f%3)
          cout<<"NO\n";
        else
          cout<<"YES\n";
      }
      else{
        if(f%3)
          cout<<"NO\n";
        else
          cout<<"YES\n";
      }
    }
}

int main() {
    FAST_IO
    ll testcases;
    sc(testcases);

    while(testcases--) {
        solve();
    }
    return 0;
}