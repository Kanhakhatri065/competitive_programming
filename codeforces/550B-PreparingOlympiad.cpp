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
vector<vector<int>> store;
void subsequences(vector<int> arr, int idx, vector<int> subarr) {
    if(idx == int(arr.size())) {
        int l = subarr.size();
        if(l != 0) {
            store.pb(subarr);
        }
    } else {
        subsequences(arr, idx + 1, subarr);
        subarr.pb(arr[idx]);
        subsequences(arr, idx + 1, subarr);
    }
}

void solve() {
    int n, l, r, x;
    cin >> n >> l >> r >> x;

    vector<int> v(n);
    forIn(v, n);
    vector<int> sub;
    subsequences(v, 0, sub);
    int cnt = 0;
    int mn, mx, sum;
    for(auto it : store) {
        sum = 0, mn = -1, mx = -1;
        for(auto i : it) {
            if(mn == -1) {
                mn = i;
            }

            if(mx == -1) {
                mx = i;
            }

            sum += i;
            mn = min(mn, i);
            mx = max(mx, i);
        }
        
        //cout << "sum : " << sum << " mx - mn : "  << (mx - mn) << endl;
        if(sum >= l && sum <= r && mx - mn >= x) {
            cnt++;
        }
    }

    pf(cnt);
}

int main() {
    FAST_IO
    solve();
    return 0;
}