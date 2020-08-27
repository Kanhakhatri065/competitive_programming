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
vector<vector<int>> adj;
string s;
ll ans;
int dfs(int root, int par, int color) {
    int curr = 0, c = s[root] - '0';
    for(auto it : adj[root]) {
        if(it != par) {
            curr += dfs(it, root, color ^ 1);
        }
    }

    if(c ^ color) {
        curr += (c == 0) ? 1 : -1;
    }

    ans += abs(curr);
    return curr;
}

void solve() {
    ll n, fans = LLONG_MAX;
    sc(n);
    ans = 0;

    adj.clear();
    adj.resize(n);

    int u, v;
    for(int i = 1;i < n;i++) {
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    sc(s);
    for(int rcolor = 0, tmp = dfs(0, 0, rcolor);(rcolor < 2);rcolor++, ans = 0, tmp = dfs(0, 0, rcolor)) {
        fans = tmp == 0 ? min(fans, ans) : fans;
    }

    //cout << "ans : ";
    cout << ((fans == LLONG_MAX) ? -1 : fans) << endl;
}

int main() {
    FAST_IO
    int t;
    sc(t);

    while(t--) {
        solve();
    }

    return 0;
}