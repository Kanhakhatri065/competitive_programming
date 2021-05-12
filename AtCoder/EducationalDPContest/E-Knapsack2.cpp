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
const ll INF = 1e18 + 5;

void solve() {
    int n, W;cin >> n >> W;
    vector<int> weight(n), values(n);
    for(int i = 0;i < n;i++) cin >> weight[i] >> values[i];

    int sum = 0;
    for(int x : values) sum += x;
    
    vector<ll> dp(sum + 1, INF);
    dp[0] = 0;
    for(int item = 0;item < n;item++) {
        for(int value_already = sum - values[item];value_already >= 0;value_already--) {
            ckmin(dp[value_already + values[item]], dp[value_already] + weight[item]);
        }
    }

    ll ans = 0;
    for(int i = 0;i <= sum;i++) {
        if(dp[i] <= W) {
            ckmax(ans,(ll)i);
        }
    }

    pf(ans);
}

int main() {
    go();
    int t;t = 1;
    while(t--) solve();
    return 0;
}
