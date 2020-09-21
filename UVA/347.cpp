/*** I came, I saw, I conquered. ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef unsigned long long ull;
#define sc(a) cin >> a
#define pf(a) cout << a << endl
#define forIn(arr, num) for(ll i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
#define mod 1000000007
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
void go() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
/*----------------------------------------------------------------*/
char in[100];
int N, sols[9999999];
 
bool check(int n) {
    int cur = n % 10;
    int d[10] = { 0 };
    while(n != 0) {
        if(d[cur] || cur == 0) return false;
        d[cur] = 1;
        n /= 10;
        cur = n % 10;
    }
    return true;
}
 
bool simul(int n) {
    if(!check(n)) return false;
    sprintf(in, "%d", n);
    int ind = 0, d[10] = {0};
    char cur = in[0] - 48;
    for(int i = 0; i < strlen(in); i++) {
        if((ind = ind + cur % strlen(in)) >= strlen(in))
            ind = ind - strlen(in);
        if(d[cur] == 1) return false;
        d[cur] = 1;
        cur = in[ind] - 48;
    }
    if(cur == in[0] - 48)
        return true;
    return false;
}
 
int main() {
    go();
    for(int i = 9876543; i > 9; i--) {
        if(simul(i))
            sols[i] = i;
        else sols[i] = sols[i + 1];
    }
    for(int T = 1;; T++) {
        scanf("%d", &N);
        if(N == 0) break;
        printf("Case %d: %d\n", T, sols[N]);
    }

    return 0;
}