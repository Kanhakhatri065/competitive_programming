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
const int N = 1e7 + 2;
int seive[N];
void pre() {
    seive[1] = 1;
    for(ll i = 2;i * i <= N;i++) {
        if(seive[i] == 0) {
            seive[i] == i;
            for(int j = 2 * i;j < N;j += i) {
                if(seive[j] == 0) {
                    seive[j] = i;
                }
            }
        }
    }
}

void solve() {
    pre();
    int n, x;
    sc(n);

    vector<int> a(n);
    forIn(a, n);

    vector<int> ans1(n, -1), ans2(n, -1);
    f(i, 0, n) {
        x = a[i];
        int ff = seive[a[i]];
        if(ff == 0) {
            continue;
        }

        while(x % ff == 0) {
            x /= ff;
        }

        if(x > 1) {
            ans1[i] = ff;
            ans2[i] = x;
        }
    }

    vpnt(ans1);
    vpnt(ans2); 
}

int main() {
    FAST_IO
    solve();
    return 0;
}