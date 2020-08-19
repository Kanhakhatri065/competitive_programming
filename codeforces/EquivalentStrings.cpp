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
void solve() {
    string s, t;
    cin >> s >> t;

    int n = s.size();

    bool flag = true;
    if(n & 1) {
        if(s != t) {
            flag = false;
        } 
    } else {
        int s1[26], s2[26];
        mem(s1, 0);
        mem(s2, 0);

        int t1[26], t2[26];
        mem(t1, 0);
        mem(t2, 0);

        for(int i = 0;i < n;i++) {
            if(i < n / 2) {
                s1[s[i] - 'a']++;
                t1[t[i] - 'a']++;
            } else {
                s2[s[i] - 'a']++;
                t2[t[i] - 'a']++;
            }
        }

        bool flag1 = true;
        for(int i = 0;i < 26;i++) {
            if(s1[i] != t1[i]) {
                flag1 = false;
            }

            if(s2[i] != t2[i]) {
                flag1 = false;
            }
        }

        bool flag2 = true;
        for(int i = 0;i < 26;i++) {
            if(s1[i] != t2[i]) {
                flag2 = false;
            }

            if(s2[i] != t1[i]) {
                flag2 = false;
            }
        }

        if(flag1 | flag2) {
            flag = true;
        } else {
            flag = false;
        }
    }

    flag ? yes : no;
}

int main() {
    FAST_IO
    solve();
    return 0;
}