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
const long long M = 2e18 + 1;
bool is_prime(int n) {
    if(n == 1) {
        return false;
    }

    for(int i = 2;i < n;i++) {
        if(n % i == 0) {
            return false;
        }
    }

    return true;
}

vector<int> primes(int n) {
    vector<int> p;
    for(int i = 1;i <= n;i++) {
        if(is_prime(i)) {
            p.pb(i);
        }
    }

    return p;
}

vector<int> g[105];
int dep[105];

void dfs(int u, int p = 0) {
    dep[u] = dep[p] + 1;
    
    for(auto v : g[u]) {
        if(v ^ p) {
            dfs(v, u);
        }
    }
}

struct DSU {
	vector<int> par, rnk, sz; int c;
	DSU(int n) : par(n + 1), rnk(n + 1,0), sz(n + 1,1), c(n) {
		for (int i = 1; i <= n; ++i) par[i] = i;
	}
	int find(int i) { return (par[i] == i ? i : (par[i] = find(par[i]))); }
	bool same(int i, int j) { return find(i) == find(j); }
	int get_size(int i) { return sz[find(i)]; }
	int count() { return c; } //connected components
	int merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return -1; else --c;
		if (rnk[i] > rnk[j]) swap(i, j);
		par[i] = j; sz[j] += sz[i];
		if (rnk[i] == rnk[j]) rnk[j]++;
		return j;
	}
};

int main() {
    FAST_IO
    vector<int> p = primes(100);
    vll v;

    for(auto x : p) {
        v.pb(x);
    }    

    while(1) {
        srt(v);
        int i = v.size() - 1;
        while(i && v[0] >= M / v[i]) {
            i--;
        }

        if(i <= 0) {
            break;
        }

        auto x = v[0];
        auto y = v[i];
        v.erase(v.begin() + i);
        v.erase(v.begin());
        v.push_back(x * y);
    }

    int t;
    sc(t);

    while(t--) {
        int n;
        sc(n);

        DSU d(n);
        for(int i = 1;i < n;i++) {
            int u, v;
            sc(u);
            sc(v);

            d.merge(u, v);
            g[u].pb(v);
            g[v].pb(u);
        }

        assert(d.count() == 1);
        dfs(1);

        for(int i = 1;i <= n;i++) {
            cout << v[dep[i] & 1] << ' ';
        }
        cout << endl;

        for(int i = 1;i <= n;i++) {
            g[i].clear();
        }
    }

    return 0;
}