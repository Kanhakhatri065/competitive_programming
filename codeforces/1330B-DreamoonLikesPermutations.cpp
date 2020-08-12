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
const int N = 2e5;
int p[N];
int ans[N][2];
int ans_cnt;
bool judge(int a[], int n) {
    static int used[N + 1];
    mem(used, 0);

    for(int i = 0;i < n;i++) {
        used[a[i]] = 1;
    }

    for(int i = 1;i <= n;i++) {
        if(!used[i]) {
            return 0;
        }
    }

    return 1;
}

bool judge(int len1, int n) {
    return judge(p, len1) && judge(p + len1, n - len1);
}

void solve() {
    ans_cnt = 0;
    int n;
    sc(n);

    int ma = 0;
    for(int i = 0;i < n;i++) {
        sc(p[i]);
        ma = max(ma, p[i]);
    }

    if(judge(n - ma, n)) {
        ans[ans_cnt][0] = n - ma;
        ans[ans_cnt++][1] = ma;
    }

    if(ma * 2 != n && judge(ma, n)) {
        ans[ans_cnt][0] = ma;
        ans[ans_cnt++][1] = n - ma;
    }

    pf(ans_cnt);
    for(int i = 0;i < ans_cnt;i++) {
        cout << ans[i][0] << " " << ans[i][1] << endl;
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