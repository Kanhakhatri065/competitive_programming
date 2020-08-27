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
const int MAX = 1e5 + 5;
int par[MAX], group[MAX];

int find_set(int n) {
    return par[n] == n ? n : find_set(par[n]);
}

void union_set(int u, int v) {
    u = find_set(u), v = find_set(v);
    if(u != v) {
        par[v] = u;
        group[u] += group[v];
    }
    cout << group[u] << endl;
}

void solve() {  
    int n;
    sc(n);

    map<string, int> mp;
    string s1, s2;

    int a = 0;
    int x, y;
    for(int i = 0;i < n;i++) {
        cin >> s1 >> s2;
        if(mp.find(s1) == mp.end()) {
            par[a] = a;
            group[a] = 1;
            mp[s1] = a++;
        }

        if(mp.find(s2) == mp.end()) {
            par[a] = a;
            group[a] = 1;
            mp[s2] = a++;
        }

        x = mp[s1], y = mp[s2];
        union_set(x, y);
    }
}

int main() {
    FAST_IO
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    sc(t);
    
    while(t--) {
        solve();
    }

    return 0;
}