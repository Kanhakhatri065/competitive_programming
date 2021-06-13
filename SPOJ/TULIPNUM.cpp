#include <bits/stdc++.h>
using namespace std;
void go() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
}

void solve() {
    int n, q;
    scanf("%d%d", &n, &q);
    int pre[n + 1];
    int x, y;
    scanf("%d", &x);
    pre[0] = 0;pre[1] = 1;
    for(int i = 1;i < n;i++) {
        scanf("%d", &y);
        if(y != x) {
            pre[i + 1] = pre[i] + 1;
        } else {
            pre[i + 1] = pre[i];
        }
        x = y;
    }

    for(int i = 0;i < q;i++) {
        scanf("%d%d", &x, &y);
        int ans;
        if(pre[x] != pre[x - 1]) {
            ans = pre[y] - pre[x - 1];
        } else {
            ans = pre[y] - pre[x - 1] + 1;
        }

        printf("%d\n", ans);
    }
}

int main() {
    go();
    int t;scanf("%d", &t);
    for(int cases = 1;cases <= t;cases++) {
        printf("Case %d:\n", cases);
        solve();
    }
    return 0;
}