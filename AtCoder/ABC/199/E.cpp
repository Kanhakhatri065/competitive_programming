#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1 << 19;
ll dp[N];
void solve() {
    int n, m, x[100], y[100], z[100];
    cin >> n >> m;
    for(int i = 0;i < m;i++) cin >> x[i] >> y[i] >> z[i];
    
    dp[0] = 1;
    for(int mask = 0;mask < (1 << n);mask++) {
        for(int i = 0;i < n;i++) {
            if(mask & (1 << i)) continue;
            bool ok = true;
            for(int j = 0;j < m;j++) {
                if(__builtin_popcount(mask | 1 << i) != x[j]) continue;
                if(__builtin_popcount((mask|1<<i)&(1<<y[j])-1)>z[j])
					ok=0; 
            }

            if(ok) dp[mask | 1 << i] += dp[mask];
        }
    }

    cout << dp[(1 << n) - 1] << endl;
}

int main() {
    int t;
    t = 1;
    while(t--) {
        solve();
    }

    return 0;
}
