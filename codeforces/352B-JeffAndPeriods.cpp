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
    int n;
    sc(n);

    vector<int> v(n);
    forIn(v, n);

    map<int, vector<int>> mp;
    for(int i = 0;i < n;i++) {
        mp[v[i]].pb(i + 1);
    }

    vector<pair<int, int>> store;
    int d;
    bool flag = true;
    for(auto it : mp) {
        if(it.ss.size() == 1) {
            store.pb({it.ff, 0});
        } else if(it.ss.size() == 2) {
            store.pb({it.ff, it.ss[1] - it.ss[0]});
        } else {
            d = it.ss[1] - it.ss[0];
            flag = true;
            for(int i = 1;i < it.ss.size();i++) {
                if(d != (it.ss[i] - it.ss[i - 1])) {
                    flag = false;
                    break;
                }
            }

            if(flag) {
                store.pb({it.ff, d});
            }
        }
    }

    pf(store.size());
    for(auto i : store) {
        cout << i.ff << " " << i.ss << endl;
    }
}

int main() {
    FAST_IO
    solve();
    return 0;
}