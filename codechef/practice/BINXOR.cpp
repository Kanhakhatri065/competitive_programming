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
const int maxn = 2e5 + 42, mod = 1e9 + 7;
 
int bpow(int x, int n) {
	return n ? n % 2 ? 1LL * x * bpow(x, n - 1) % mod : bpow(1LL * x * x % mod, n / 2) : 1;
}
int inv(int x) {
	return bpow(x, mod - 2);
}
 
int F[maxn];
int fact(int n) {
	return n ? F[n] ? F[n] : F[n] = 1LL * n * fact(n - 1) % mod : 1;
}
int rfact(int n) {
	return inv(fact(n));
}
int nCr(int n, int r) {
	return 1LL * fact(n) * rfact(r) % mod * rfact(n - r) % mod;
}
 
void solve() {
    int n;
    sc(n);
    
    string a, b;
    sc(a);
    sc(b);

    int a_one = count(all(a), '1');
    int b_one = count(all(b), '1');

    int l = abs(a_one - b_one);
    int r = a_one + b_one - 2 * max(0, a_one + b_one - n);

    int ans = 0;
    for(int k = l;k <= r;k += 2) {
        ans = (ans + nCr(n, k)) % mod;
    }

    pf(ans);
}

int main() {
    FAST_IO
    int t;
    sc(t);

    while(t--) {
        solve();
    }

    return 0;
}