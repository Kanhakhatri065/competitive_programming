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
bool isSubArray(vll A, vll B, ll n, ll m) 
{ 
    ll i = 0, j = 0; 
  
    while (i < n && j < m) { 
  
         
        if (A[i] == B[j]) { 
            i++; 
            j++; 
  
            if (j == m) {
                return true; 
            }
        } 
        
        else { 
            i = i - j + 1; 
            j = 0; 
        } 
    } 
  
    return false; 
} 

void solve() {
    ll n, m;
    sc(n);
    sc(m);

    vll v[m];
    ll temp;
    f(i, 0, m) {
        f(j, 0, n) {
            sc(temp);
            v[i].pb(temp);
        }
    }

    ll count = n;
    ll temp_count = 0;
    f(i, 0, n) {
        vll v_temp;
        v_temp.pb(v[0][i]);
        f(j, i + 1, n) {
            v_temp.pb(v[0][j]);

            temp_count = 0;
            f(k, 1, m) {
                if(isSubArray(v[k], v_temp, v[k].size(), v_temp.size())) {
                    temp_count++;
                }
            }

            if(temp_count == m - 1) {
                count++;
            }
        }
        v_temp.clear();
    }

    pf(count);
}

int main() {
    FAST_IO
    solve();
    return 0;
}