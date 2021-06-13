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
const int MOD = 1e9 + 7;
const int N = 1002;
const int INF = 1e9;

int n, m,x, y, a[N][2], dp[N][2];
char arr[N][N];

void solve() {
    cin >> n >> m >> x >> y;

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> arr[i][j];
            if(arr[i][j] == '#') a[j][0]++;
            else a[j][1]++;
        }
    }

    for(int j = 1;j <= m;j++) {
        a[j][0] += a[j - 1][0];
        a[j][1] += a[j - 1][1];

        dp[j][0] = INF;
        dp[j][1] = INF;
    }

    for(int i = 0;i < m;i++) {
        for(int j = x;j <= y;j++) {
            ckmin(dp[i + j][0], dp[i][1] + a[i + j][0] - a[i][0]);
            ckmin(dp[i + j][1], dp[i][0] + a[i + j][1] - a[i][1]);
        }
    }

    pf(min(dp[m][0], dp[m][1]));
}

int main() {
    go();
    int t = 1;
    while(t--) solve();
    return 0;
}