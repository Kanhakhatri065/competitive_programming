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
const int MAX = 2e5 + 5;
/*-------------- Push your limits here ---------------------------*/
void solve() {
	double a, b, c, d;
	cin >> a >> b >> c >> d;

	double m = (a * d + b * c) / (b + d);
	cout << fixed << setprecision(10) << m << endl;
}

int main() {
	ssolve
	return 0;
}
