#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void go() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
}

const int MAX = 2e5 + 5;

vector<ll> store[MAX];

void solve() {
    int n;
    scanf("%d", &n);

    vector<int> u(n);
    for(int i = 0;i < n;i++) scanf("%d", &u[i]);
    vector<int> s(n);
    for(int i = 0;i < n;i++) scanf("%d", &s[i]); 

    for(int i = 1;i <= n;i++) store[i].clear();

    ll sum = 0;
    for(int i = 0;i < n;i++) {
        sum += s[i];
        store[u[i]].push_back(s[i]);
    }

    for(int i = 1;i <= n;i++) if(!store[i].empty()) sort(store[i].begin(), store[i].end());

    vector<vector<ll>> length_partial(n + 1);
    for(int j = 1;j <= n;j++) {
        int len = int(store[j].size());

        if(length_partial[len].empty()) length_partial[len].assign(len + 1, 0);

        ll partial = 0;
        for(int i = 0;i < len;i++) {
            partial += store[j][i];
            length_partial[len][i + 1] += partial;
        }
    }

    vector<ll> remove_from_sum(n + 1);
    for(int i = 1;i <= n;i++) {
        if(!length_partial[i].empty()) {
            for(int k = 1;k <= n;k++) {
                remove_from_sum[k] += length_partial[i][i % k];
            }
        }
    }

    for(int i = 1;i <= n;i++) {
        printf("%lld ", (sum - remove_from_sum[i]));
    }
    printf("\n");
}

int main() {
    go();
    int t;
    scanf("%d", &t);
    while(t--) solve();

    return 0;
}