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
    int n, m;
    cin >> n >> m;

    int b[n][m];
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            sc(b[i][j]);
        }
    }    

    int a[n][m];
    mem(a, -1);

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(b[i][j] == 0) {
                for(int k = 0;k < n;k++) {
                    a[k][j] = 0;
                }

                for(int k = 0;k < m;k++) {
                    a[i][k] = 0;
                }
            }
        }
    }

    bool flag = true;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(b[i][j] == 1) {
                bool flag2 = false;
                for(int k = 0;k < n;k++) {
                    if(a[k][j] == -1 || a[k][j] == 1) {
                        a[k][j] = 1;
                        flag2 = true;
                    }
                }

                for(int k = 0;k < m;k++) {
                    if(a[i][k] == -1 || a[i][k] == 1) {
                        a[i][k] = 1;
                        flag2 = true;
                    }
                }

                if(!flag2) {
                    flag = false;
                    break;  
                } 
            }
        }
    }

    if(flag) {
        yes;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        no;
    }
}

int main() {
    FAST_IO
    solve();
    return 0;
}