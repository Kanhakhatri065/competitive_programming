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
    int n, m, c;
    int t = 0;
    int blank = 0;
    while(cin >> n >> m >> c) {
        if(!n && !m && !c) {
            break;
        }
        t++;

        vector<int> v(n + 1);
        vector<int> vis(n + 1, false);
        for(int i = 1;i <= n;i++) {
            cin >> v[i];
        }

        int cnt = 0;
        int mx = 0;
        int x;
        for(int i = 0;i < m;i++) {
            sc(x);

            if(vis[x]) {
                vis[x] = false;
                cnt -= v[x];
                mx = max(mx, cnt);
            } else {
                vis[x] = true;
                cnt += v[x];
                mx = max(mx, cnt);
            }

            //cout << "mx : " << mx << endl;
        }   


        cout << "Sequence " << t << endl;
        if(mx > c) {
            cout << "Fuse was blown." << endl;
        } else {
            cout << "Fuse was not blown." << endl;
            cout << "Maximal power consumption was " << mx << " amperes." << endl;
        }

        cout << endl;

        blank++;
    }
}

int main() {
    FAST_IO
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
    return 0;
}