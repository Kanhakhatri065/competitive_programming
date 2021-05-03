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
void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    if((a + b - c) > n || (a + b - c == 1 && n >= 2)) {
        pf("IMPOSSIBLE");
    } else if(n == 1) {
        pf(1);
    } else if(n == 2) {
        if(c == 2) {
            pf("1 1");
        } else if(a == 2) {
            pf("1 2");
        } else if(b == 2) {
            pf("2 1");
        } else {
            assert(false);
        }
    } else {
        vector<int> res;
        res.reserve(n);

        for(int i = 0;i < a - c;i++) {
            res.pb(2);
        }

        for(int i = 0;i < c;i++) {
            res.pb(3);
        }

        for(int i = 0;i < b - c;i++) {
            res.pb(2);
        }

        int extra = n - (a + b - c);

        if(extra > 0) {
            res.insert(res.begin() + 1, extra, 1);
        }

        vpnt(res);
    }
}

int main() {
    FAST_IO
    int t;
    sc(t);

    for(int tt = 1;tt <= t;tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }

    return 0;
}