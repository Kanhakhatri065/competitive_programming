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
const int N = 1e4 + 10;
const int INF = 1e9;

bool sieve[N];
void precomputation() {
    mem(sieve, true);

    for(int i = 2;i < N;i++) {
        if(sieve[i]) {
            for(int j = 2 * i; j < N;j += i) {
                sieve[j] = false;
            }
        }
    }
}


void solve() {
    int n;
    sc(n);

    vector<int> v(n);
    forIn(v, n);

    int mx = *max_element(all(v));
    int ans = INF;

    for(int g = 2;g <= mx + 1;g++) {
        if(sieve[g] == false) {
            continue;
        }

        int cans = 0, last = 0;
        for(int i = 0;i < n;i++) {
            if(last < v[i]) {
                last = (v[i] + g - 1) / g * g;
            }

            cans += last - v[i];
        }

        ans = min(ans, cans);
    }

    pf(ans);
}

int main() {
    FAST_IO
    int t;
    sc(t);

    precomputation();

    while(t --> 0) {
        solve();
    }

    return 0;
}