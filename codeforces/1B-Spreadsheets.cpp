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
    string s;
    sc(s);

    ll n = s.size(), x = 0;
    for(int i = 1;i < n;i++) {
        if(s[i - 1] >= 'A' && s[i - 1] <= 'Z' && s[i] >= '0' && s[i] <= '9') {
            x++;
        }
    }

    if(x == 2) {
        string t, u, ans;
        for(int i = 1;i < n;i++) {
            if(s[i] == 'C') {
                u = s.substr(i + 1);
                break;
            } else {
                t += s[i];
            }
        }

        int num = stoi(u);
        while(num > 0) {
            char c = 64 + ((num % 26 != 0) ? (num % 26) : 26);
            ans = c + ans;
            num = (num % 26 == 0) ? (num - 1) / 26 : num / 26;
        }

        ans += t;
        pf(ans);
    } else {
        string t, u;
        ll ans = 0;
        for(int i = 0;i < n;i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                u = s.substr(i);
                break;
            } else {
                t += s[i];
            }
        }

        for(ll i = t.size() - 1;i >= 0;i--) {
            ans += (t[i] - 64) * pow(26, t.size() - i - 1);
        }

        string out = "R" + u + "C" + to_string(ans);
        pf(out);
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