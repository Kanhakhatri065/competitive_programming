/*
	I love the sound you make when you shut up.
*/
#include <bits/stdc++.h>
using namespace std;
/*----typedefs--------*/
typedef long long ll;typedef pair<int, int> pi;typedef pair<long long, long long> pl;
typedef vector<int> vi;typedef vector<pair<int, int>> vpi;typedef vector<long long> vl;typedef vector<vector<int>> vvi;
typedef map<int, int> mi;typedef map<long long, long long> ml;typedef map<int, vector<int>> mivi;
typedef set<int> si;typedef set<long long> sl;typedef set<pair<int, int>> spi;
typedef queue<int> qi;typedef queue<pair<int, int>> qpi;
/*-----in and out--------*/
#define pf(a) cout << a << endl
#define forIn(arr, num) for(int i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(int i = 0; i < int(ans.size()); i++) cout << ans[i] << (i + 1 < int(ans.size()) ? ' ' : '\n');
/*---useful defines------*/
#define sz(x) (int)(x).size()
#define pb push_back
#define mem(a, b) memset(a,(b), sizeof(a))
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
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
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
}
/*-------- movement in a 2D array ------*/
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
/*----------------------------------------------------------------*/
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
/*-------------- Push your limits here ---------------------------*/
void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> dsu(2 * n);
	vector<int> deg(2 * n);
	vector<int> empt(2 * n);

	for(int i = 0;i < 2 * n;i++) dsu[i] = i;
	function<int(int)> get = [&] (int v) {
		if(v == dsu[v]) return v;
		return dsu[v] = get(dsu[v]);
	};

	function<void(int, int)> uni = [&] (int u, int v) {
		dsu[get(u)] = get(v);
	};

	vector<vpi> graph(2 * n);
	vector<char> used_e(m);
	map<pi, int> id;
	for(int i = 0;i < m;i++) {
		int r, c;
		cin >> r >> c;
		r--, c--;

		empt[r]++, empt[c]++;
		id[{r, c + n}] = i;
		id[{c + n, r}] = i;
		graph[r].pb({c + n, i});
		graph[c + n].pb({r, i});
		deg[r] ^= 1, deg[c + n] ^= 1;
		uni(r, c + n);
	}

	bool bad = false;
	int cnt = 0;
	int start = 0;
	set<int> ok;


}

int main() {
	int t;
	cin >> t;

	while(t--) {
		solve();
	}

	return 0;
}
