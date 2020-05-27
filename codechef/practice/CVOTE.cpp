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
    ll n, m;
    sc(n);
    sc(m);

    map<string, ll> names;
    map<string, ll> countries;
    map<string, string> chefs_countries;

    string name, country;
    f(i, 0, n) {
        sc(name);
        sc(country);
        chefs_countries[name] = country;
    }

    f(i, 0, m) {
        sc(name);
        names[name]++;
        countries[chefs_countries[name]]++;
    }

    map<string, ll>::iterator it = countries.begin();
    ll max_count = it->ss;
    country = it->ff;
    for(auto i : countries) {
        if(max_count < i.ss) {
            max_count = i.ss;
            country = i.ff;
        } else if(max_count == i.ss) {
            if(i.ff < country) {
                country = i.ff;
            }
        }
    }

    it = names.begin();
    max_count = it->ss;
    name = it->ff;
    for(auto i : names) {
        if(max_count < i.ss) {
            max_count = i.ss;
            name = i.ff;
        } else if(max_count == i.ss) {
            if(i.ff < name) {
                name = i.ff;
            }
        }
    }

    pf(country);
    pf(name);
}

int main() {
    FAST_IO
    solve();
    return 0;
}