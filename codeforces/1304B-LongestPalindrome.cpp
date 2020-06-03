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
/*** Swapping ***/
void swapll(ll *a,ll *b){ll tmp=*a;*a=*b;*b=tmp;}
void swapc(char *a,char *b){char tmp=*a;*a=*b;*b=tmp;}
/*----------------------------------------------------------------*/
bool isPalindrome(string s) {
    f(i, 0, s.length() / 2) {
        if(s[i] != s[s.length() - i - 1]) {
            return false;
        }
    }

    return true;
}

void solve() {
    ll n, m;
    sc(n);
    sc(m);

    vector<string> v(n);
    forIn(v, n);

    vector<string> store2;
    vector<string> storesinglepalindrome;

    int flag = 0;
    string revstr;
    f(i, 0, n) {
        if(v[i] == "0") {
            continue;
        }
        flag = 0;
        revstr = "";
        for(ll j = m - 1;j >= 0;j--) {
            revstr += v[i][j];
        }

        f(j, i + 1, n) {
            if(revstr == v[j]) {
                flag = 1;
                v[j] = "0";
                break;
            }
        }

        if(flag == 1) {
            store2.pb(v[i]);
        } else {
            if(isPalindrome(v[i])) {
                storesinglepalindrome.pb(v[i]);
            }
        }
    }

    string out = "";
    if(!storesinglepalindrome.empty()) {
        ll max_length = storesinglepalindrome[0].length();
        ll idx = 0;
        f(i, 0, storesinglepalindrome.size()) {
            if(max_length < storesinglepalindrome[i].length()) {
                max_length = storesinglepalindrome[i].length();
                idx = i;
            }
        }

        out += storesinglepalindrome[idx];
    }

    if(!store2.empty()) {
        string temp = "";
        f(i, 0, store2.size()) {
            temp += store2[i];
            reverse(all(store2[i]));
        }

        out = temp + out;
        temp = "";
        for(ll i = store2.size() - 1;i >= 0;i--) {
            out += store2[i];
        }
    }

    pf(out.size());
    pf(out);


}

int main() {
    FAST_IO
    solve();
    return 0;
}