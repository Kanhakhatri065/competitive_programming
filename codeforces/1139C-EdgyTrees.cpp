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
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

int pow(int a, int b, int m) {
    int ans = 1;

    while(b) {
        if(b & 1) {
            ans = (ans * a) % m;
        }
        b /= 2;
        a = (a * a) % m;
    }

    return ans;
}

int n, k, sz, ans = 0;
bool visited[N];
vector<int> graph[N];
void dfs(int u) {
    if(visited[u]) {
        return;
    }
    
    sz++;
    visited[u] = 1;
    for(int it : graph[u]) {
        dfs(it);
    }
}

void solve() {
    cin >> n >> k;
    ans = pow(n, k, MOD);

    for(int i = 1;i <= n - 1;i++) {
        int u, v, x;
        cin >> u >> v >> x;
        if(x == 0) {
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }

    for(int i = 1;i <= n;i++) {
        if(visited[i]) {
            continue;
        }

        sz = 0;
        dfs(i);
        ans -= pow(sz, k, MOD);
        ans += MOD;
        ans %= MOD;
    }

    pf(ans);
}

int32_t main() {
    go();
    solve();
    return 0;
}