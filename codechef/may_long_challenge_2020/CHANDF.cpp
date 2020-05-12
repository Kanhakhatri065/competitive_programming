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

string decimalToBinary(ll n) {
    string bin = "";
    for(ll i = 0;n > 0;i++) {
        if(n % 2 == 0) {
            bin += '0';
        } else {
            bin += '1';
        }
        n /= 2;
    }

    reverse(all(bin));

    return bin;
}

ll binaryToDecimal(string bin) {
    ll n = 0;
    ll base = 1;
    for(ll i = bin.size() - 1;i >= 0;i--) {
        if(bin[i] == '1') {
            n += base;
        }
        base *= 2;
    }

    return n;
}

ull largestNum(ull n) 
{ 
  
    ull num = 0; 
  
    for (int i = 0; i <= 64; i++) { 
        int x = (1 << i); 
  
        if ((x - 1) <= n) {
            num = (1 << i) - 1; 
        } else {
            break;
        }
    } 
  
    return num; 
} 
  

void solve() {
    ull x, y, l, r;
    sc(x);
    sc(y);
    sc(l);
    sc(r);

    string binary_z(decimalToBinary(r).size(), '1');
    ull z = 0;

    int flag = 0;
    for(ll i = 0;i < binary_z.size();i++) {
        flag = 0;
        for(ll j = binary_z.size() - 1;j >= i;j--) {
            binary_z[j] = '0';
            z = binaryToDecimal(binary_z);
            if(z <= r) {
                flag = 1;
                break;
            }
            binary_z[i] = '1';
        }

        if(flag == 1) {
            break;
        }

        binary_z[i] = '0';
    }
    
    z = binaryToDecimal(binary_z);

    pf(z - 1);
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