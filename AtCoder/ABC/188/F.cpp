/*
    I love the sound you make when you shut up.
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
/*----typedefs--------*/
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
using ll = long long;
using pi = pair<int, int>;
/*-----in and out--------*/
#define pf(a) cout << a << endl
#define forIn(arr, num) for(int i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(int i = 0; i < int(ans.size()); i++) cout << ans[i] << (i + 1 < int(ans.size()) ? ' ' : '\n');
/*---useful defines------*/
#define sz(x) (int)(x).size()
#define pb push_back
#define mem(a, b) memset(a,(b), sizeof(a))
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
/*----- the binary answer of life-----*/
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
/*---checking and pushing-----*/
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
/*---- FAST I/O and file read ---*/
void go() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
}
/*-------- test-case stuff--------------*/
#define ssolve solve();
#define msolve int T;cin >> T;while(T--) {solve();}
#define mcsolve int T;cin >> T;for(int tt = 1;tt <= T;tt++) {cout << "Case #" << tt << ": ";solve();}
/*-------- movement in a 2D array ------*/
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
/*----------------------------------------------------------------*/
const int MOD = 1e9 + 7;
const int N = 101;
/*-------------- Push your limits here ---------------------------*/
ll n, m;
ll v[101];
ll s[101];
ll dp[101];

ll itv(int low, int hig) {
    ll ret1 = 0, ret2 = v[hig + 1] + v[low];
    for(int i = low;i <= hig;i++) {
        if(s[i]) ret1 += v[i];
        else ret2 += v[i];
    }

    return min(ret1, ret2);
}

ll work(int mov, ll x) {
    mem(s, 0);
    mem(v, 0);
    mem(dp, 0);

    int len = 0;
    if(x < 0) x = -x;
    ll tmp = x;

    while(tmp) {
        s[len] = tmp & 1;
        len++;
        tmp >>= 1;
    }

    for(int i = 0;i <= mov;i++) v[i] = 1;
    for(int i = mov + 1;i <= len + 1;i++) v[i] = (1LL << (i - mov));

    for(int i = 0;i <= len;i++) {
        dp[i] = itv(0, i);
        for(int j = 0;j < i;j++) {
            dp[i] = min(dp[i], dp[j] + itv(j + 1, i));
        }
    }

    return dp[len] + mov;
}

void solve() {
    cin >> n >> m;

    if(n >= m) {
        pf(n - m);
        return;
    }

    ll ans = 2e18;
    for(int mov = 0;;mov++) {
        ans = min(ans, work(mov, (n << mov) - m));
        if((n << mov) > m) break;
    }

    pf(ans);
}

int main() {
    //go();
    ssolve
    return 0;
}
