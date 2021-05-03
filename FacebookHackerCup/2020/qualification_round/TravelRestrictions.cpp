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

    string incom, outcom;
    sc(incom);
    sc(outcom);

    char out[n][n];
    mem(out, 'Y');
    int cnt;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            if(i != j) {
                if(j > i) {
                    //pf("C11 start");
                    cnt = 0;
                    for(int k = i + 1;k <= j;k++) {
                        if(incom[k] == 'N') {
                            cnt++;
                        }
                    }

                    for(int k = i;k < j;k++) {
                        if(outcom[k] == 'N') {
                            cnt++;
                        }
                    }

                    if(cnt) {
                        out[i][j] = 'N';
                    } else {
                        out[i][j] = 'Y';
                    }
                    //pf("C11 end");
                } else {
                    //pf("C12 start");
                    cnt = 0;
                    for(int k = i - 1;k >= j;k--) {
                        if(incom[k] == 'N') {
                            cnt++;
                        }
                    }

                    for(int k = i;k > j;k--) {
                        if(outcom[k] == 'N') {
                            cnt++;
                        }
                    }

                    if(cnt) {
                        out[i][j] = 'N';
                    } else {
                        out[i][j] = 'Y';
                    }
                    //pf("C12 end");
                }
            } else {
                //pf("C2");
                out[i][j] = 'Y';
            }
        }
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cout << out[i][j];
        }
        cout << endl;
    }
}

int main() {
    FAST_IO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int t;
    sc(t);

    for(int tt = 1;tt <= t;tt++) {
        cout << "Case #" << tt << ":" << endl;
        solve();
    }

    return 0;
}