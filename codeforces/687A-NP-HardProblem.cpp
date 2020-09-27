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
const int MAX = 1e5 + 5;
vector<int> vc[2];
vector<int> g[MAX];
int mark[MAX];
bool dfs(int v, int color = 2) {
    mark[v] = color;
    vc[color - 1].push_back(v);
    for(auto it : g[v]) {
        if(!mark[it] && dfs(it, 3 - color)) {
            return 1;
        }

        if(mark[it] != 3 - color) {
            return 1;
        }
    }

    return 0;
}

void solve() {
    int n, m;
    cin >> n >> m;

    int src, dest;
    for(int i = 0;i < m;i++) {
        cin >> src >> dest;
        src--, dest--;

        g[src].pb(dest);
        g[dest].pb(src);
    }

    for(int i = 0;i < n;i++) {
        if(!mark[i]) {
            if(g[i].empty()) {
                continue;
            }

            if(dfs(i)) {
                pf(-1);
                return;
            }
        }
    }

    for(int i = 0;i < 2;i++) {
        pf(int(vc[i].size()));
        for(auto it : vc[i]) {
            cout << (it + 1) << " ";
        }
        cout << endl;
    }
}

int main() {
    go();
    solve();
    return 0;
}