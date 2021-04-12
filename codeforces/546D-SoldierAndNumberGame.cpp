/*
    I love the sound you make when you shut up.
*/
#include <bits/stdc++.h>
using namespace std;
void go() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
}
using ll = long long;
const int N = 5e6 + 5;
/*-------------- Push your limits here ---------------------------*/
ll sieve[N];
void precomputation() {
    memset(sieve, 0, sizeof(sieve));
    for(int i = 2;i < N;i++) {
        if(sieve[i] == 0) {
            for(int j = i;j < N;j += i) {
                int p = j;
                while(p % i == 0) {
                    sieve[j]++;
                    p /= i;
                }
            }
        }
    }

    for(int i = 3;i < N;i++) sieve[i] += sieve[i - 1];
}

void solve() {
    int a, b;
    scanf("%d%d", &a, &b);

    ll ans = sieve[a] - sieve[b];
    printf("%lld\n", ans);
}

int main() {
    go();
    precomputation();
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
