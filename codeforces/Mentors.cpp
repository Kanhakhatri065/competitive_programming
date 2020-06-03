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
#define mp make_pair
#define mem(name, value) memset(name, value, sizeof(name))
#define pp pair
/*** STLs ***/
typedef vector<ll>vll;typedef set<ll>sll;typedef multiset<ll>msll;
typedef queue<ll>qll;typedef map<ll,ll>mll;typedef pair<ll,ll>pll;
typedef vector<pair<ll,ll>>vpll;
/*** Sorts ***/
#define all(v) (v).begin(), (v).end()
#define srt(v) sort(all(v))
#define srtGreat(v) sort(all(v), greater<ll>())
/*** Bit-Stuff ***/
#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
/*** Some Prints ***/
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
/*** Swapping ***/
void swapll(ll *a,ll *b){ll tmp=*a;*a=*b;*b=tmp;}
void swapc(char *a,char *b){char tmp=*a;*a=*b;*b=tmp;}
/*----------------------------------------------------------------*/
void solve() {
    ll n, k;
    sc(n);
    sc(k);

    vll v(n + 1), cnt(n + 1);
    map<ll, vll> m;
    f(i, 1, n + 1) {
        sc(v[i]);
        m[v[i]].pb(i);
    }

    vector<vll> g(n + 1);

    ll f, s;
    f(i, 1, k + 1) {
        sc(f);
        sc(s);

        g[f].pb(v[s]);
        g[s].pb(v[f]);
    }

    ll idx;
    f(i, 1, n + 1) {
        g[i].pb(0);
        srt(g[i]);
        idx = lower_bound(all(g[i]), v[i]) - g[i].begin();
        cnt[i] = idx - 1;
    }

    vll ans(n + 1);
    ll counter = 0;
    for(auto it : m) {
        for(auto x : it.ss) {
            ans[x] = counter;
        }
        counter += (it.ss.size());
    }

    f(i, 1, n + 1) {
        cout << (ans[i] - cnt[i]) << " ";
    }
    cout << endl;
}

int main() {
    FAST_IO
    solve();
    return 0;
}