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
const int MAX = 100, MAXN = 105;
int a[MAXN];
void solve() {
    int n;
    sc(n);

    for(int i = 0;i < n;i++) {
        sc(a[i]);
    }

    vector<pair<int, int>> cnts;
    int cnt = 1, which = a[0];
    for(int i = 1;i < n;i++) {
        if(a[i] == a[i - 1]) {
            cnt++;
        } else {
            cnts.pb({which, cnt});
            which = a[i];
            cnt = 1;
        }
    }

    if(cnt > 0) {
        cnts.pb({which, cnt});
    }

    bool ok = true;
    if(cnts.size() == 13) {
        for(int i = 0;i < 13;i++) {
            if(cnts[i] != cnts[13 - i - 1]) {
                ok = false;
            }

            if(i < 7 && cnts[i].ff != i + 1) {
                ok = false;
            }
        }
    } else {
        ok = false;
    }

    if(ok) {
        pf("yes");
    } else {
        pf("no");
    }
}

int main() {
    FAST_IO
    int t;
    sc(t);

    while(t--) {
        solve();
    }

    return 0;
}