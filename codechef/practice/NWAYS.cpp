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
const int N = 2e6 + 6;
const int mod = 1e9 + 7;
ll fac[N];

ll power(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b & 1) {
			ans = (ans * a) % mod;
		}

		a = (a * a) % mod;
		b /= 2;
	}

	return ans;
}

ll nCr(ll n, ll r) {
	ll ans = (fac[n] * power(fac[r], mod - 2)) % mod;

	return (ans * power(fac[n - r], mod - 2)) % mod;
}

void precomputation() {
	fac[0] = fac[1] = 1;
	for(int i = 2;i < N;i++) {
		fac[i] = (i * fac[i - 1]) % mod;
	}
}

void solve() {
	ll n, k;
	sc(n);
	sc(k);

	ll ans = (2 * nCr(n + k + 1, n - 1) + mod - n) % mod;
	pf(ans);
}

int main() {
	FAST_IO
	int t;
	sc(t);

	precomputation();

	while(t--) {
		solve();
	}

	return 0;
}
