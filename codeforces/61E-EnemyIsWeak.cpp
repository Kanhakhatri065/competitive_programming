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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define int long long

struct BIT {
    int N;
    vector<int> bit;
 
    BIT(int n) {
        N = n;
        bit.assign(n + 1, 0);
    }
 
    void add(int idx, int val) {
        for (; idx <= N; idx += idx & (-idx))
            bit[idx] += val;
    }
 
    int pref(int idx) {
        int ans = 0;
        for (; idx > 0; idx -= idx & (-idx))
            ans += bit[idx];
        return ans;
    }
 
    int sum(int a, int b) {
        return pref(b) - pref(a - 1);
    }
 
};
 
void solve() {
    int n;
    cin >> n;
 
    vector<int> v(n);
    ordered_set st;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        st.insert(v[i]);
    }
    for (auto &x: v)x = st.order_of_key(x) + 1;
    struct BIT a(n), b(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += b.sum(v[i] + 1, n);
        b.add(v[i], a.sum(v[i] + 1, n));
        a.add(v[i], 1);
    }
    cout << ans << endl;
}

int32_t main() {
    FAST_IO
    solve();
    return 0;
}