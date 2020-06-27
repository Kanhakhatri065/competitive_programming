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
/*----------------------------------------------------------------*/
const int P = 5;

int powmod(int x, int n, int P) {
    x %= P;
    int res = 1 % P;

    while(n) {
        if(n & 1) {
            (res *= x) %= P;
            n--;
        } else {
            (x *= x) %= P;
            n >>= 1;
        }
    }

    return res;
}

int myPow(int x, string s, int P) {
    x %= P;
    int res = 1 % P;
    int now = x;

    for(int i = s.length() - 1;i >= 0;i--) {
        (res *= powmod(now, s[i] - '0', P)) %= P;
        now = powmod(now, 10, P);
    }

    return res;
}

void solve() {
    string s;
    sc(s);

    int res = myPow(1, s, P) + myPow(2, s, P) + myPow(3, s, P) + myPow(4, s, P);
    res %= P;

    pf(res);
}

int main() {
    FAST_IO
    solve();
    return 0;
}