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
const int MAX = 2e5 + 200;
vector<int> graph[MAX];
bool used[MAX];

void addEdge(int v, int u) {
    graph[v].pb(u);
    graph[u].pb(v);
}

void dfs(int v) {
    used[v] = 1;
    for(int it : graph[v]) {
        if(!used[it]) {
            dfs(it);
        }
    }
}

void solve() {
    int n;
    sc(n);

    for(int i = 0;i < n;i++) {
        string s;
        sc(s);

        for(char c : s) {
            addEdge(i, n + c - 'a');
        }
    }

    int res = 0;    
    for(int i = n;i < (n + 26);i++) {
        if(!graph[i].empty() && !used[i]) {
            dfs(i);
            res++;
        }
    }

    pf(res);
}

int main() {
    go();
    solve();
    return 0;
}