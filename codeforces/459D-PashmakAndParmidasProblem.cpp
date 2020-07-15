/*** I came, I saw, I conquered. ***/
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;typedef unsigned long long ull;
/*** Input Output ***/
#define sc(a) cin >> a
#define pf(a) cout << a << endl
/*** Loops ***/
#define f(i, p, num) for(ll i = p; i < num; i++)
#define forIn(arr, num) for(ll i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
/*** Define Values ***/
#define mod1 1000000007
#define mod2 998244353
#define eps 1e-7
/*** Abbrevations **/
#define pb push_back
#define ff first
#define ss second
#define mem(name, value) memset(name, value, sizeof(name))
/*** STLs ***/
typedef vector<ll>vll;typedef set<ll>sll;typedef multiset<ll>msll;
typedef map<ll,ll>mll;typedef pair<ll,ll>pll;
/*** Sorts ***/
#define all(v) (v).begin(), (v).end()
#define srt(v) sort(all(v))
/*** Bit-Stuff ***/
#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
/*** Some Prints ***/
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
/*----------------------------------------------------------------*/
const int MAXN = 1e6 + 10;
int fen[MAXN];

void add(int x, int val) {
    for(int i = x + 1;i < MAXN;i += (i & (-i))) {
        fen[i] += val;
    }
}

int get(int x) {
    int ans = 0;
    for(int i = x;i > 0;i -= (i & (-i))) {
        ans += fen[i];
    }

    return ans;
}

int sum(int x, int y) {
    return get(y) - get(x);
}

int rem[MAXN], cnt[MAXN], a[MAXN], tot[MAXN], sz;

void solve() {
    int n;
    sc(n);

    for(int i = 0;i < n;i++) {
        sc(a[i]);
        tot[sz++] = a[i];
    }

    sort(tot, tot + sz);
    sz = unique(tot, tot + sz) - tot;

    for(int i = 0;i < n;i++) {
        a[i] = lower_bound(tot, tot + sz, a[i]) - tot;
    }

    for(int i = n - 1;i >= 0;i--) {
        cnt[a[i]]++;
        add(cnt[a[i]], 1);

        rem[i] = cnt[a[i]];
    }

    mem(cnt, 0);
    ll ans = 0;
    for(int i = 0;i < n;i++) {
        add(rem[i], -1);
        cnt[a[i]]++;
        ans += sum(1, cnt[a[i]]);
    }

    pf(ans);
}   

int main() {
    FAST_IO
    solve();
    return 0;
}