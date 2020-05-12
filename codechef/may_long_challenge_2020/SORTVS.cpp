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
bool isSorted(ll arr[], ll n) {
    for(ll i = 0;i < n;i++) {
        if(arr[i] != i + 1) {
            return false;
        }
    }

    return true;
}

ll minSwaps(ll arr[], ll n) { 
    pll arrPos[n]; 
    for0(n) { 
        arrPos[i].first = arr[i]; 
        arrPos[i].second = i; 
    } 
  
    sort(arrPos, arrPos + n); 
    
    vector<bool> vis(n, false); 
  
    ll ans = 0; 
  
    for0(n) { 
        if (vis[i] || arrPos[i].second == i) { 
            continue; 
        }

        ll cycle_size = 0; 
        ll j = i; 
        while (!vis[j]) { 
            vis[j] = 1; 
  
            j = arrPos[j].second; 
            cycle_size++; 
        } 
  
        if (cycle_size > 0) 
        { 
            ans += (cycle_size - 1); 
        } 
    } 
  
    return ans; 
} 


void solve() {
    ll n, m;
    sc(n);
    sc(m);

    ll arr1[n];
    forIn(arr1, n);

    ll arr2[m][2];
    for0(m) {
        sc(arr2[i][0]);
        sc(arr2[i][1]);
    }

    int flag = 0;

    for0(m) {
        swapll(&arr1[arr2[i][0] - 1], &arr1[arr2[i][1] - 1]);
        if(isSorted(arr1, n)) {
            flag = 1;
            break;
        }
    }

    ll count = 0;
    if(flag) {
        pf(count);
    } else {
        count = minSwaps(arr1, n);
        pf(count);
    }

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