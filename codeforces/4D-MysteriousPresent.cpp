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
const int N = 5005;

int n, w[N], h[N], to[N], d[N];

int dp(int v) {
    if(d[v]) return d[v];
    d[v] = 1;
    for(int i = 0;i <= n;i++) {
        if(w[i] > w[v] && h[i] > h[v]) {
            if(dp(i) + 1 > d[v]) {
                to[v] = i;
                d[v] = d[i] + 1;
            }
        }
    }

    return d[v];
}

void solve() {
    cin >> n;

    for(int i = 0;i <= n;i++) cin >> w[i] >> h[i];
    for(int i = 0;i <= n;i++) to[i] = -1;
    dp(0);

    d[0]--;
    pf(d[0]);
    for(int i = to[0];i != -1;i = to[i]) cout << i << " ";
    cout << endl;
}

int main() {
    go();
    int t = 1;
    while(t--) solve();
    return 0;
}