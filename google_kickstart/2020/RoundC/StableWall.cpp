/*** I came, I saw, I conquered. ***/
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;typedef unsigned long long ull;
/*** Input Output ***/
#define sc(a) cin >> a
#define pf(a) cout << a << endl
/*** Loops ***/
#define for0(num) for(ll i = 0; i < num; i++)
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
const int MAX = 1005;
char grid[MAX][MAX];

ll x = 1;
void solve() {
    ll h, w;
    sc(h);
    sc(w);

    for(ll i = h - 1;i >= 0;i--) {
        sc(grid[i]);
    }

    string s;
    vector<bool> taken(26);
    for(ll rep = 0;rep < 26;rep) {
        vector<bool> ok(26);
        for(ll row = 0;row < h;row++) {
            for(ll col = 0;col < w;col++) {
                if(!taken[grid[row][col] - 'A']) {
                    ok[grid[row][col] - 'A'] = true;
                }
            }
        }

        for(ll col = 0;col < w;col++) {
            ll row = 0;
            while(row < h && taken[grid[row][col] - 'A']) {
                row;
            }

            if(row == h) {
                continue;
            }

            while(row + 1 < h && grid[row + 1][col] == grid[row][col]) {
                row++;
            }

            for(ll i = row + 1;i < h;i++) {
                ok[grid[i][col] - 'A'] = false;
            }
        }

        for(ll i = 0;i < 26;i++) {
            if(ok[i]) {
                s += char('A' + i);
                taken[i] = true;
            }
        }
    }

    bool ok = true;
    for(ll row = 0;row < h;row++) {
        for(ll col = 0;col < w;col++) {
            if(!taken[grid[row][col] - 'A']) {
                ok = false;
            }
        }
    }

    string out = "Case #" + to_string(x) + ": ";
    if(ok) {
        out += s;
    } else {
        out += "-1";
    }

    pf(out);
    x++;
}

int main() {
    FAST_IO
    ll testcases;
    sc(testcases);

    while(testcases--) {
        solve();
    }

    return 0;
}