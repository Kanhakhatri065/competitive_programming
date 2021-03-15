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
const int N = 1e6 + 5;
/*-------------- Push your limits here ---------------------------*/
bool sieve[N];
int cnt[N];
void precomputation() {
    memset(sieve, true, sizeof(sieve));

    sieve[0] = sieve[1] = false;
    for(int i = 2;i < N;i++) {
        if(sieve[i]) {
            for(int j = 2 * i;j < N;j += i) sieve[j] = false;
        }
    }

    cnt[0] = cnt[1] = 0;
    for(int i = 2;i < N;i++) {
        cnt[i] += cnt[i - 1];
        if(sieve[i]) cnt[i]++;
    }
}

void solve() {
    int x, y;
    scanf("%d%d", &x, &y);

    int num = cnt[x];

    if(y >= num) {
        printf("Chef\n");
    } else {
        printf("Divyam\n");
    }
}

int main() {
    go();
    precomputation();
    int t;
    scanf("%d", &t);

    while(t--) {
        solve();
    }

    return 0;
}
