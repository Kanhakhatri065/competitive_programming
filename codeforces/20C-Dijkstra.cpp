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
#define int int64_t

const int N = 1e5 + 1;
const int INF = 1e18;

int n, m;
int d[N], pre[N];
vector<pair<int, int>> g[N];
priority_queue<pair<int, int>> q;
void Dijkstra() {
    fill(d, d + N, INF);
 
    d[1] = 0;
    pre[1] = -1;
    q.emplace(0, 1);
 
    while (!q.empty()) {
        int u = q.top().second;
        int du = -q.top().first;
        q.pop();
 
        if (du != d[u]) continue;
 
        for (auto e : g[u]) {
            int v = e.first;
            int w = e.second;
 
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.emplace(-d[v], v);
                pre[v] = u;
            }
        }
    }
}

void solve() {
	cin >> n >> m;
	while(m--) {
		int u, v, c;
		cin >> u >> v >> c;
		g[u].emplace_back(v, c);
		g[v].emplace_back(u, c);
	}

	Dijkstra();

	if(d[n] == INF) {
		pf(-1);
		return;
	}

	stack<int> s;
	for(int i = n ;i != -1;i = pre[i]) {
		s.push(i);
	}

	while(!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

signed main() {
	FAST_IO
	solve();
	return 0;
}
