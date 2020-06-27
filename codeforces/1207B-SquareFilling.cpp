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
    int n, m;
    sc(n);
    sc(m);

    int v[n][m];
    f(i, 0, n) {
        f(j, 0, m) {
            sc(v[i][j]);
        }
    }

    vector<pair<int, int>> store;
    f(i, 0, n - 1) {
        f(j, 0, m - 1) {
            if(v[i][j] * v[i][j + 1] * v[i + 1][j] * v[i + 1][j + 1] > 0) {
                v[i][j] = 2;
                v[i][j + 1] = 2;
                v[i + 1][j] = 2;
                v[i + 1][j + 1] = 2;
                store.pb({i + 1, j + 1});
            }
        }
    }

    int cnt = 0;
    f(i, 0, n) {
        f(j, 0, m) {
            if(v[i][j] == 1) {
                cnt++;
            }
        }
    }

    if(cnt) {
        pf(-1);
    } else {
        if(store.empty()) {
            pf(0);
        } else {
            pf(store.size());
            f(i, 0, store.size()) {
                cout << store[i].ff << " " << store[i].ss << endl;
            }
        }
    }
}

int main() {
    FAST_IO
    solve();
    return 0;
}