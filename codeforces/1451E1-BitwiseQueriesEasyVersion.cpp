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
const int maxn = (1LL << 16) + 5;
const int minn = 4;
const int maxncheck = (1LL << 16);
/*-------------- Push your limits here ---------------------------*/
int n, xorvals[maxn], ans[maxn];
void andqueries(string s, int & dest) {
	cout << s << endl;
	cout.flush();
	cin >> dest;
	if(dest == -1) {
		exit(0);
	}
	return;
}

void solve() {
	cin >> n;
	for(int i = 2;i <= n;i++) {
		cout << "XOR 1 " << i << endl;
		cout.flush();
		cin >> xorvals[i];
		if(xorvals[i] == -1) {
			return;
		}
	}

	int xor12 = xorvals[2], xor13 = xorvals[3], xor23 = xorvals[2] ^ xorvals[3];
	int and12, and13, and23;
	andqueries("AND 1 2", and12);
	andqueries("AND 1 3", and13);
	andqueries("AND 2 3", and23);

	int x = xor12 + 2 * and12;
	int y = xor13 + 2 * and13;
	int z = xor23 + 2 * and23;
	
	ans[1] = (x + y - z) / 2;
	for(int i = 2;i <= n;i++) {
		ans[i] = (xorvals[i] ^ ans[1]);
	}
	cout << "! ";

	for(int i = 1;i <= n;i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	cout.flush();
}

int main() {
	ssolve
	return 0;
}
