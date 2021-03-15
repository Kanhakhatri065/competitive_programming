#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    scanf("%d", &n);

    vector<int> v(n);
    for(int i = 0;i < n;i++) {
        scanf("%d", &v[i]);
    }

    sort(v.begin(), v.end());
    for(int i = 0;i < n;i++) {
        if(v[i] > (i + 1)) {
            printf("Second\n");
            return;
        }
    }

    long long ans = 0;
    for(int i = 0;i < n;i++) ans += (i + 1) - v[i];

    if(ans & 1) {
        printf("First\n");
    } else {
        printf("Second\n");
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int t;
    scanf("%d", &t);
    while(t--) {
        solve();
    }

    return 0;
}