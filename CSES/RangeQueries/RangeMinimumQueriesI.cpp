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
void construct_seg_tree(vll &segtree, vll &a, int n) {
    for(int i = 0;i < n;i++) {
        segtree[n + i] = a[i];
    }
 
    for(int i = n - 1;i >= 0;i--) {
        segtree[i] = min(segtree[2 * i], segtree[2 * i + 1]);
    }
}
 
ll range_query(vll &segtree, int left, int right, int  n) {
    left += n;
    right += n;
 
    ll mn = 1e9;
 
    while(left < right) {
        if(left & 1) {
            mn = min(mn, segtree[left]);
            left++;
        }
 
        if(right & 1) {
            right--;
            mn = min(mn, segtree[right]);
        }
 
        left /= 2;
        right /= 2;
    }
 
    return mn;
}
 
void solve() {
    int n, q;
    sc(n);
    sc(q);
 
    vll v(n);
    forIn(v, n);
 
    vll segtree(2 * n);
    construct_seg_tree(segtree, v, n);
 
    int left, right;
    for(int i = 0;i < q;i++) {
        cin >> left >> right;
        left--;
        pf(range_query(segtree, left,right, n));
    }
}
 
int main() {
    FAST_IO
    solve();
    return 0;
}