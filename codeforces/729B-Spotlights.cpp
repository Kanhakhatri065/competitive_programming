/*
	I love the sound you make when you shut up.
*/
#include <bits/stdc++.h>
using namespace std;
/*----typedefs--------*/
typedef long long ll;typedef long double ld;typedef complex<ld> cd;
typedef pair<int, int> pi;typedef pair<ll, ll> pl;typedef pair<ld, ld> pd;
typedef vector<int> vi;typedef vector<pi> vpi;typedef vector<ll> vl;typedef vector<ld> vd;typedef vector<pl> vpl;
typedef vector<cd> vcd;typedef vector<vi> vvi;
typedef map<int, int> mi;typedef map<ll, ll> ml;typedef map<int, vi> mivi;typedef map<int, pi> mipi;
typedef set<int> si;typedef set<ll> sl;typedef set<pair<int, int>> spi;
typedef queue<int> qi;typedef queue<pi> qpi;
/*-----in and out--------*/
#define sc(a) cin >> a
#define pf(a) cout << a << endl
#define forIn(arr, num) for(ll i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(int i = 0; i < int(ans.size()); i++) cout << ans[i] << (i + 1 < int(ans.size()) ? ' ' : '\n');
/*-----traversals--------*/
#define trav(it, a) for(auto &it : a)
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
/*---useful defines------*/
#define sz(x) (int)(x).size()
#define pb push_back
#define mem(a, b) memset(a,(b), sizeof(a))
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
/*--- bit-stuff ----*/
#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
/*----- the binary answer of life-----*/
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
/*---checking and pushing-----*/
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
/*---- FAST I/O and file read ---*/
void go() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
/*------ single or multiple testcase-----*/
#define ssolve solve();
#define msolve int t;sc(t);while(t--) {solve();}
#define mcsolve int t;sc(t);for(int tt = 1;tt <= t;tt++) {cout << "Case #" << tt << ": ";solve();}
/*-------- movement in a 2D array ------*/
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
/*----------------------------------------------------------------*/
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int N = 2e5 + 5;
const int MAX = 1005;
/*-------------- Push your limits here ---------------------------*/
int arr[MAX][MAX];
int lef[MAX][MAX], righ[MAX][MAX], up[MAX][MAX], down[MAX][MAX];
int n, m;
void solve() {
	cin >> n >> m;

	F0R(i, n) {
		F0R(j, m) {
			sc(arr[i][j]);
		}
	}

	mem(up, 0);
	F0R(i, n) {
		F0R(j, m) {
			up[i][j] += arr[i][j];
			if(i > 0) {
				up[i][j] += up[i - 1][j];
			}
		}
	}

	mem(down, 0);
	F0Rd(i, n) {
		F0R(j, m) {
			down[i][j] += arr[i][j];
			if(i + 1 < n) {
				down[i][j] += down[i + 1][j];
			}
		}
	}

	mem(righ, 0);
	F0R(i, n) {
		F0R(j, m) {
			righ[i][j] += arr[i][j];
			if(j > 0) {
				righ[i][j] += righ[i][j - 1];
			}
		}
	}

	mem(lef, 0);
	F0R(i, n) {
		F0Rd(j, m) {
			lef[i][j] += arr[i][j];
			if(j + 1 < m) {
				lef[i][j] += lef[i][j + 1];
			}
		}
	}

	ll cnt = 0LL;
	F0R(i, n) {
		F0R(j, m) {
			if(arr[i][j] == 0) {
				if(up[i][j]) cnt++;
				if(down[i][j]) cnt++;
				if(lef[i][j]) cnt++;
				if(righ[i][j]) cnt++;
			}
		}
	}

	pf(cnt);
}

int main() {
	go();
	ssolve
	return 0;
}
