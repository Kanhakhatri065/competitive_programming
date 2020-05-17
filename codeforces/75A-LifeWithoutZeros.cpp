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
void solve() {
    ll a, b;
    sc(a);
    sc(b);

    ll c = a + b;

    string str_a = to_string(a);
    string str_b = to_string(b);
    string str_c = to_string(c);

    string removed_zero_a = "";
    for0(str_a.size()) {
        if(str_a[i] != '0') {
            removed_zero_a += str_a[i];
        }
    }
    
    string removed_zero_b = "";
    for0(str_b.size()) {
        if(str_b[i] != '0') {
            removed_zero_b += str_b[i];
        }
    }
    
    string removed_zero_c = "";
    for0(str_c.size()) {
        if(str_c[i] != '0') {
            removed_zero_c += str_c[i];
        }
    }

    ll new_a;
    stringstream s1(removed_zero_a);
    s1 >> new_a;

    ll new_b;
    stringstream s2(removed_zero_b);
    s2 >> new_b;

    ll new_c;
    stringstream s3(removed_zero_c);
    s3 >> new_c;

    ll re_c = new_a + new_b;

    if(new_c == re_c) {
        yes;
    } else {
        no;
    }
}

int main() {
    FAST_IO
    solve();
    return 0;
}