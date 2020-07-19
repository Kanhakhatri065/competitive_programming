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
#define mem(name, value) memset(name, value, sizeof(name))
/*** STLs ***/
typedef vector<ll>vll;typedef set<ll>sll;typedef multiset<ll>msll;
typedef map<ll,ll>mll;typedef pair<ll,ll>pll;
/*** Sorts ***/
#define all(v) (v).begin(), (v).end()
#define srt(v) sort(all(v))
/*** Bit-Stuff ***/
#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
/*** Some Prints ***/
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
/*----------------------------------------------------------------*/
long long fac(ll n) {
    ll f = 1;
    for(ll i = 1;i <= n;i++) {
        f *= i;
    }

    return f; 
}

void solve() {
    string s, t;
    sc(s);
    sc(t);

    int plus1 = 0;
    int minus1 = 0;
    for(int i = 0;i < (int)s.length();i++) {
        if(s[i] == '+') {
            plus1++;
        } else {
            minus1++;
        }
    }

    int plus2 = 0, minus2 = 0, unknown = 0;
    for(int i = 0;i < (int) t.length();i++) {
        if(t[i] == '+') {
            plus2++;
        } else if(t[i] == '-') {
            minus2++;
        } else {
            unknown++;
        }
    }

    double ans;
    if(plus2 > plus1 or minus2 > minus1) {
        ans = 0.0;
    } else {
        //cout << "unknown : " << unknown << endl;
        ll total = pow(2, unknown);
        ll arrangement = fac(unknown);
        ll similar_plus = fac(plus1 - plus2);
        ll similar_minus = fac(minus1 - minus2);

        ll selected = arrangement / (similar_minus * similar_plus);
        //cout << "Arrangement : " << arrangement << " similar plus : " << similar_plus << " similar_minus : " << similar_minus << endl;
        //cout << "Selected : " << selected <<"Total : " << total << endl;

        ans = (double) selected / total; 
    }


    cout << fixed << setprecision(12) << ans << endl;
}

int main() {
    FAST_IO
    solve();
    return 0;
}