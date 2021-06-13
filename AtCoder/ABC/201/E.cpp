#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pf(a) cout << a << endl
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
void go() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
}
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
    int n;cin >> n;
    vector<vector<ll>> edge(n), weight(n);

    for(int i = 1;i < n;i++) {
        ll u, v, w;cin >> u >> v >> w;
        u--, v--;
        edge[u].pb(v);
        edge[v].pb(u);
        weight[u].pb(w);
        weight[v].pb(w);
    }

    vector<ll> dist(n, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for(int i = 0;i < sz(edge[now]);i++) {
            int to = edge[now][i];
            ll sum = dist[now] ^ weight[now][i];
            if(dist[to] == -1) {
                dist[to] = sum;
                q.push(to);
            }
        }
    }

    ll ans = 0;
    for(int i = 0;i < 60;i++) {
        vector<int> cnt(2);
        for(int j = 0;j < n;j++) cnt[(dist[j] >> i) & 1]++;
        ans += (1LL << i) % MOD * cnt[0] % MOD * cnt[1];
        ans %= MOD;
    }

    pf(ans);
}

int main() {
    go();
    int t = 1;
    while(t--) solve();
    return 0;
}