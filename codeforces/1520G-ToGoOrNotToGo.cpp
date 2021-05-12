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
#ifdef LOCAL
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
}

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const ll INF = 1e18;

void bfs(int sx, int sy, vector<vector<int>> &d, vector<vector<int>> &a) {
    int n = sz(d), m = sz(d[0]);
    queue<pair<int, int>> q;
    q.push({sx, sy});
    d[sx][sy] = 1;
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for(int i = 0;i < 4;i++) {
            int tx = x + d4i[i], ty = y + d4j[i];
            if(tx >= 0 && ty >= 0 && tx < n && ty < m && d[tx][ty] == 0 && a[tx][ty] != -1) {
                d[tx][ty] = d[x][y] + 1;
                q.push({tx, ty});
            }
        }
    }

    for(auto &e : d) {
        for(auto &i : e) i--;
    }
}

void solve() {
    int n, m, w;
    scanf("%d%d%d", &n, &m, &w);

    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> d1(n, vector<int>(m));
    vector<vector<int>> d2(n, vector<int>(m));

    for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) scanf("%d", &a[i][j]);

    bfs(0, 0, d1, a);
    bfs(n - 1, m - 1, d2, a);


    ll best = INF;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(d2[i][j] != -1 && a[i][j] >= 1) {
                ckmin(best, a[i][j] + 1LL * w * d2[i][j]);
            }
        }
    }

    ll ans = 1LL * w * d1[n - 1][m - 1];
    if(d1[n - 1][m - 1] == -1) {
        ans = INF;
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(d1[i][j] != -1 && a[i][j] >= 1 && best != INF) {
                ckmin(ans, 1LL * w * d1[i][j] + a[i][j] + best);
            }
        }
    }

    if(ans == INF) printf("-1\n");
    else printf("%lld\n", ans);
}

int main() {
    go();
    int t;t = 1;
    while(t--) solve();
    return 0;
}