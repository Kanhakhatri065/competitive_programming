/*
    I love the sound you make when you shut up.
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
/*-------typedefs------*/
template<class T> using ordered_set = tree<T, null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update> ;
using ll = long long;
using pi = pair<int, int>;
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
/*-------- test-case stuff--------------*/
#define ssolve solve();
#define msolve int T;cin >> T;while(T--) {solve();}
#define mcsolve int T;cin >> T;for(int tt = 1;tt <= T;tt++) {cout << "Case #" << tt << ": ";solve();}
/*-------- movement in a 2D array ------*/
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
/*----------------------------------------------------------------*/
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
/*-------------- Push your limits here ---------------------------*/
void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    ll g[n + 1];
    vector<pair<int, ll>> reward[n + 1];
    for(int i = 1;i <= n;i++) cin >> g[i];
    for(int i = 1;i <= m;i++) {
        int u, v;ll d;
        cin >> u >> v >> d;
        reward[v].pb({u, d});
    }

    for(int i = 1;i <= n;i++) sort(all(reward[i]));
    
    vector<ll> dp[n + 1][n + 1];
    dp[0][0].pb(0);
    for(int i = 1;i <= n;i++) {
        ll rew_added = g[i];
        for(auto r : reward[i]) rew_added += r.ss;

        int ptr = 0;
        for(int j = 0;j < i;j++) {
            while(ptr < sz(reward[i]) && reward[i][ptr].ff <= j) {
                rew_added -= reward[i][ptr].ss;
                ptr++;
            }

            for(auto r : dp[i - 1][j]) {
                dp[i][j].pb(rew_added + r);
            }
        }

        for(int j = 0;j < i;j++) {
            for(auto r : dp[i - 1][j]) {
                dp[i][i].pb(r);
            }
        }

        sort(all(dp[i][i]), greater<ll>());
        while(sz(dp[i][i]) > k) dp[i][i].pop_back();
    }

    vector<ll> final_vals;
    for(int i = 0;i <= n;i++) {
        for(auto r : dp[n][i]) {
            final_vals.pb(r);
        }
    }

    sort(all(final_vals), greater<ll>());
    for(int i = 0;i < k;i++) cout << final_vals[i] << " ";
    cout << endl;
}

int main() {
    go();
    msolve
    return 0;
}
