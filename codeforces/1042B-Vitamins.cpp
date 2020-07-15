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
/*----------------------------------------------------------------*/
const int INF = 1e9;
map<string, int> was;

inline int getC(string a, string b) {
    if(!was.count(a) || !was.count(b)) {
        return INF;
    }

    return was[a] + was[b];
}

void solve() {
    int n, c;
    string s;
    sc(n);
    for(int i = 0;i < n;i++) {
        sc(c);
        sc(s);

        srt(s);
        if(was.count(s) == 0) {
            was[s] = c;
        } else {
            was[s] = min(was[s], c);
        }
    }

    int ans = INF;
    if(was.count("A") && was.count("B") && was.count("C")) {
        ans = was["A"] + was["B"] + was["C"];
    }

    if(was.count("ABC")) {
        ans = min(ans, was["ABC"]);
    }

    ans = min(ans, getC("AB", "C"));
    ans = min(ans, getC("A", "BC"));
    ans = min(ans, getC("AC", "B"));
    ans = min(ans, getC("AB", "BC"));
    ans = min(ans, getC("AC", "BC"));
    ans = min(ans, getC("AC", "AB"));

    if(ans == INF) {
        ans = -1;
    }

    pf(ans);
}

int main() {
    FAST_IO
    solve();
    return 0;
}