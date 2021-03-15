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
const int N = 105;
vector<int> graph[N];
int visited[N];
int n;

void bfs() {
    queue<pair<int, int>> q;
    q.push({1, 1});

    while(!q.empty()) {
        int v = q.front().first, x = q.front().second;
        q.pop();
        visited[v] = x;
        for(auto it : graph[v]) {
            if(visited[it] == 0) {
                if(x == 1) {
                    q.push({it, 2});
                } else {
                    q.push({it, 1});
                }
            }
        }
    }
}

void solve() {
    cin >> n;

    for(int i = 1;i < n;i++) {
        int src, dest;
        cin >> src >> dest;

        graph[src].pb(dest);
        graph[dest].pb(src);
    }

    memset(visited, 0, sizeof(visited));
    bfs();
    for(int i = 1;i <= n;i++) {
        cout << visited[i] << " ";
    }
    cout << endl;

    for(int i = 1;i <= n;i++) {
        graph[i].clear();
    }
}

int main() {
    go();
    int t;
    sc(t);

    while(t--) {
        solve();
    }

    return 0;
}