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
const int N = 2002;

char s[N][N];
int a[N][N], dp[N][N];
int n, m;

void solve() {
    cin >> n >> m;

    for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) cin >> s[i][j];

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(s[i][j] == '+') a[i][j] = 1;
            else a[i][j] = -1;
        }
    }

    memset(dp, 63, sizeof(dp));
    dp[n][m] = 0;
    for(int i = n;i > 0;i--) {
        for(int j = m;j > 0;j--) {
            if(i == n && j == m) continue;
            dp[i][j] = max(a[i + 1][j] - dp[i + 1][j], a[i][j + 1] - dp[i][j + 1]);
        }
    }

    if(dp[1][1] > 0) {
        pf("Takahashi");
    } else if(dp[1][1] < 0) {
        pf("Aoki");
    } else {
        pf("Draw");
    }
}

int main() {
    go();
    int t = 1;
    while(t--) solve();
    return 0;
}