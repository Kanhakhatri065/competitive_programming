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
const int MAX = 5e3 + 2;
int p[MAX], ranks[MAX];

int findp(int x) {
    return p[x] == x ? x : findp(p[x]);
}

void joint(int x, int y) {
    x = findp(x), y = findp(y);

    if(x != y) {
        p[x] = y;
        ranks[y] += ranks[x];
    }
}

void solve() {
    int c, r;
    string cmd;

    while(cin >> c >> r) {
        if(!c && !r) {
            break;
        }

        map<string, int> mp;
        for(int i = 0;i < c;i++) {
            sc(cmd);
            mp[cmd] = i;
            p[i] = i;
            ranks[i] = 1;
        }

        int j, k;
        for(int i = 0;i < r;i++) {
            sc(cmd);
            j = mp[cmd];

            sc(cmd);
            k = mp[cmd];

            joint(j, k);
        }

        int ans = 0;
        for(int i = 0;i < c;i++) {
            ans = max(ans, ranks[i]);
        }

        pf(ans);
    }
}

int main() {
    FAST_IO
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
    return 0;
}