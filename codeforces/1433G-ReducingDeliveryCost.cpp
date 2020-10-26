/*** I came, I saw, I conquered. ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef unsigned long long ull;
#define sc(a) cin >> a
#define pf(a) cout << a << endl
#define forIn(arr, num) for(ll i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
#define mod 1000000007
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
void go() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
/*----------------------------------------------------------------*/
const int INF = 1e9;
int n;
vector<vector<int>> d;
vector<vector<pair<int, int>>> g;
void dijkstra(int s, vector<int> &d) {
	d = vector<int>(n, INF);
	d[s] = 0;
	
	set<pair<int, int>> st;
	st.insert({d[s], s});
	
	while(!st.empty()) {
		int v = st.begin()->second;
		st.erase(st.begin());
		for(auto [to, w] : g[v]) {
			if(d[to] > d[v] + w) {
				auto it = st.find({d[to], to});
				
				if(it != st.end()) {
					st.erase(it);
				}

				d[to] = d[v] + w;
				st.insert({d[to], to});
			}
		}
	}
}

void solve() {
	int m, k;
	cin >> n >> m >> k;

	g = vector<vector<pair<int, int>>>(n);
	
	for(int i = 0;i < m;i++) {
		int x, y, w;
		cin >> x >> y >> w;
		--x, --y;

		g[x].push_back({y, w});
		g[y].push_back({x, w});
	}

	vector<pair<int, int>> r(k);
	for(auto &[a, b] : r) {
		cin >> a >> b;
		--a, --b;
	}

	d = vector<vector<int>>(n);
	for(int v = 0;v < n;v++) {
		dijkstra(v, d[v]);
	}

	int ans = INF;
	for(int v = 0;v < n;v++) {
		for(auto [to, w] : g[v]) {
			int cur = 0;
			for(auto [a, b] : r) {
				cur += min({d[a][b], d[a][v] + d[to][b], d[a][to] + d[v][b]});
			}
			ans = min(ans, cur);
		}
	}

	pf(ans);
}

int main() {
	solve();
	return 0;
}
