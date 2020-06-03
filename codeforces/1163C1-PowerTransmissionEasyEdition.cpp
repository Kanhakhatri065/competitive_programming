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
    ll n;
    sc(n);

    ll coordinates[n][2];
    f(i, 0, n) {
        sc(coordinates[i][0]);
        sc(coordinates[i][1]);
    }

    map<pll, sll> f;
    ll total = 0, res = 0;
    ll x1, x2, y1, y2, a, b, c, d;
    f(i, 0, n - 1) {
        f(j, i + 1, n) {
            x1 = coordinates[i][0], y1 = coordinates[i][1];
            x2 = coordinates[j][0], y2 = coordinates[j][1];

            a = y1 - y2;
            b = x1 - x2;

            d = __gcd(a, b);
            a /= d;
            b /= d;

            if(a < 0 || (a == 0 && b < 0)) {
                a = -a;
                b = -b;
            }

            c = a * x1 - b * y1;
            if(!f[{a, b}].count(c)) {
                total++;
                f[{a, b}].insert(c);
                res += total - f[{a, b}].size();
            }
        }
    }

    pf(res);
}

int main() {
    FAST_IO
    solve();
    return 0;
}