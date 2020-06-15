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
ll bpow(ll x, ll v) {	
	if (v == 0) {
		return 1 % mod1;
    }
 
	if (v % 2 == 1) {
		return (x * bpow(x, v - 1)) % mod1;
    }
 
	ll r = bpow(x, v / 2);
 
	return (r * r) % mod1;	
}

void solve() {
    int n, x;
	cin >> n >> x;
	vector < ll > a(n), b;
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];	
	}

	for(int i = 0; i < n; i++) {
	 	b.push_back(sum - a[i]);
    }

    srtGreat(b);             
 
	while (true) {
		ll v = b[b.size() - 1];
    
    	int cnt = 0;
		while (b.size() > 0 && b[b.size() - 1] == v) {
			cnt ++;
			b.pop_back();
		}
        
        if (cnt % x != 0) {
            v = min(v, sum);
			cout << bpow(x, v) << endl;
			return;
		}
		else {
			cnt /= x;
			for(int i = 0; i < cnt; i++) {
				b.push_back(v + 1);
            }
		}	
	}
}

int main() {
    FAST_IO
    solve();
    return 0;
}