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
string s;
int k, far[100001], n, raf[100001];
ll sumfar[100001];
void precomputation(){
    int count0 = 0, count1 = 0;
    if(s[1] == '1') count1 += 1;
    else count0 += 1;
    int j = 1;
    for(int i = 1; i <= n; i++){
        while(j <= n and count0 <= k and count1 <= k){
            j += 1;
            if(j > n) break;
            if(s[j] == '1') count1 += 1;
            else count0 += 1;
        }
        far[i] = j;
        if(s[i] == '1')
            count1--;
        else count0--;
    }
    for(int i = 1; i <= n; i++){
        sumfar[i] = far[i] + sumfar[i-1];
    }
    for(int i = 1; i <= n; i++){
        raf[i] = -1;
    }
    for(int i = n; i >= 1; i--){
        raf[far[i] - 1] = i;
    }
    for(int i = n; i >= 1; i--){
        if(raf[i] == -1) raf[i] = raf[i+1];
    }
}
ll answer_query(int l, int r){
    k = max(l, raf[r]) - 1;
    ll ans = sumfar[k] - sumfar[l-1] + (r - k) * 1LL * (r + 1) - r * 1LL * (r + 1)/2 + l * 1LL * (l - 1)/2;
    return ans;
}

void solve() {
    int q;
    sc(n);
    sc(k);
    sc(q);
    sc(s);
    s = ' ' + s;

    precomputation();
    int l, r;
    while(q--) {
        sc(l);
        sc(r);
        pf(answer_query(l, r));
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