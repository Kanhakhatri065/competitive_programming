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
void construct_segment_tree(vector<int>& segtree,  vector<int> &a, int n) { 
    for (int i = 0; i < n; i++)  {
        segtree[n + i] = a[i];     
    }
  
    for (int i = n - 1; i >= 1; i--) {
        segtree[i] = min(segtree[2 * i],  segtree[2 * i + 1]); 
    }
} 
  
void update(vector<int>& segtree, int pos, int value,  int n) { 
    pos += n; 
  
    segtree[pos] = value; 
  
    while (pos > 1) { 
        pos >>= 1; 
        segtree[pos] = min(segtree[2 * pos], segtree[2 * pos + 1]); 
    } 
} 
  
int range_query(vector<int>& segtree, int left, int right, int n) { 
    left += n; 
    right += n; 
  
    int mi = (int)1e9; 
  
    while (left < right) { 
  
        if (left & 1) { 
            mi = min(mi, segtree[left]);   
            left++; 
        } 
  
        if (right & 1) {   
            right--; 
            mi = min(mi, segtree[right]); 
        } 
  
        left /= 2; 
        right /= 2; 
    } 

    return mi; 
} 

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    forIn(v, n);

    vector<int> segtree(2 * n);
    construct_segment_tree(segtree, v, n);

    int type, l, r;
    int ans;
    while(q--) {
        cin >> type >> l >> r;
        if(type == 1) {
            update(segtree, l - 1, r, n);
        } else {
            l--;
            ans = range_query(segtree, l, r, n);
            pf(ans);
        }
    }
}

int main() {
    FAST_IO
    solve();
    return 0;
}