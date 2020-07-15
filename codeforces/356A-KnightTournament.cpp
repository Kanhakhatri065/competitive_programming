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
const int MAXN = 3e5 + 5;
bool st[4 * MAXN];
int ans[MAXN];

void update(int id, int l, int r, int u, int v, int k) {
	if(st[id]) {
		return;
	}

	if(r < u || l > v) {
		return;
	}

	if(l == r) {
		if(r == k) {
			return;
		}

		st[id] = true;
		ans[r] = k;
		return;
	}

	int mid = (l + r) / 2;
	update(2 * id, l, mid, u, v, k);
	update(2 * id + 1, mid + 1, r, u, v, k);
	st[id] = min(st[2 * id], st[2 * id + 1]);
}

void solve() {
	int n, m;
	sc(n);
	sc(m);

	int l, r, x;
	while(m--) {
		sc(l);
		sc(r);
		sc(x);

		update(1, 1, n, l, r, x);
	}

	for(int i = 1;i <= n;i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}

int main() {
	FAST_IO
	solve();
	return 0;
}
