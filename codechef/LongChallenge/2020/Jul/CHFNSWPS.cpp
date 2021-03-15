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
/*----------------------------------------------------------------*/
void solve() {
    int n;
    sc(n);

    int mn = INT_MAX;
    map<int, int> mp, mp1, mp2;
    
    vector<int> a(n);
    f(i, 0, n) {
        sc(a[i]);
        mn = min(mn, a[i]);
        mp[a[i]]++;
    }

    vector<int> b(n);
    f(i, 0, n) {
        sc(b[i]);
        mn = min(mn, b[i]);
        mp[b[i]]++;
    }

    int flag = 0;
    for(auto i : mp) {
        if(i.ss % 2) {
            flag = 1;
            break;
        } else {
            mp1[i.ff] = i.ss / 2;
        }
    }

    if(flag) {
        pf(-1);
        return;
    }

    mp2 = mp1;
    vector<int> v1, v2;
    f(i, 0, n) {
        if(mp1[a[i]] > 0) {
            mp1[a[i]]--;
        } else {
            v1.pb(a[i]);
        }
    }

    f(i, 0, n) {
        if(mp2[b[i]]) {
            mp2[b[i]]--;
        } else {
            v2.pb(b[i]);
        }
    }

    sort(all(v1));
    sort(all(v2), greater<int>());

    ll y = v1.size();
    if(y == 0) {
        pf(0);
    } else {
        ll ans = 0;
        f(i, 0, y) {
            ans += min(2 * mn, min(v1[i], v2[i]));
        }

        pf(ans);
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