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
#define int long long
const int N = 55;

int n, m, k;
int a[N];
vector<int> reqd;
map<vector<int>, double> cache;
bool check(vector<int> cur) {
    for(int i = 0; i < m; i++)
		if(cur[i] > reqd[i])
			return 0;
	return 1;
}

double dp(vector<int> v) {
    if(v == reqd) {
		return 0;
    }

	if(cache.find(v) != cache.end()) {
		return cache[v];
    }
	
    int tot = 0;
	double num = 1;

	for(int i = 0; i < m; i++) {
		vector<int> nv = v;
		nv[i]++;
		sort(nv.begin(), nv.end());
		if(check(nv)) {
			num += dp(nv) / m;
        } else {
			tot++;
        }
	}
	
    double frac = 1 - (double)tot / m;
	
    num = num / frac;

	return cache[v] = num;
}

void solve() {
    reqd.clear();
    cache.clear();

    cin >> n >> m >> k;
    
    for(int i = k + 1; i <= m; i++) {
        reqd.push_back(0);
    }
    
    for(int i = 1; i <= k; i++) {
        cin >> a[i];
        reqd.push_back(a[i]);
    }

    vector<int> v;
    for(int i = 1; i <= m; i++) {
        v.push_back(0);
    }
    
    double ans = dp(v);
    cout << fixed << setprecision(12) << ans;
    cout << endl;
}

int32_t main() {
    go();
    int t;
    sc(t);

    for(int tt = 1;tt <= t;tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }

    return 0;
}