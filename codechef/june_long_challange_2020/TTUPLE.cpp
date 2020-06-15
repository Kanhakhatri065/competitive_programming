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
const int MAXN = 100*1000 + 5;
 
inline ll mulFac(ll a,ll b,ll c,ll d){
	if(b != a and (d-c)%(b-a) == 0){
		return (d-c)/(b-a);
	}else{
		return 1;
	}
}
 
inline bool equal(ll* a, ll* b){
	f(i, 0, 3) {
        if(a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int best;

void solve(ll* a,ll* b,int num = 0){
	if(num >= best) {
        return;
    }

    if(equal(a,b)){
		best = min(best,num);
		return;
	}

	if(num >= 2) {
        return;
    }

	set<ll> add;
	add.insert(b[0]-a[0]);
	add.insert(b[1]-a[1]);
	add.insert(b[2]-a[2]);

	set<ll> mult;
	
    f(i, 0, 3) {
        if(a[i] != 0 and b[i]%a[i] == 0) {
            mult.insert(b[i]/a[i]);
        }
    }

	mult.insert(mulFac(a[0],a[1],b[0],b[1]));
	mult.insert(mulFac(a[2],a[1],b[2],b[1]));
	mult.insert(mulFac(a[0],a[2],b[0],b[2]));
	mult.insert(0);
	
	f(mask,1,8) {
		vector<int> all;
		f(j, 0, 3) {
            if(mask&(1<<j)) {
                all.pb(j);
            }
        }

        for(auto x: add){
			ll aa[3];
			f(j, 0, 3) {
                aa[j] = a[j];
            }

        	for(auto e: all) {
                aa[e]+=x;
            }

			solve(aa,b,num+1);
		}
		for(auto x:mult){
			ll aa[3];
			f(j, 0, 3) {
                aa[j] = a[j];
            }

			for(auto e: all) {
                aa[e]*=x;
            }
            
			solve(aa,b,num+1);
		}
 
	}
}
 
void solve(){
	best = 3;
	ll a[3];
	ll b[3];
	cin >> a[0] >> a[1] >> a[2];
	cin >> b[0] >> b[1] >> b[2];
	solve(a,b);
	cout << best << endl;
}

int main() {
    ll t;
    sc(t);

    while(t--) {
        solve();
    }

    return 0;
}