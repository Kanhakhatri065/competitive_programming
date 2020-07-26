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
vector<pair<ll, ll>> dish;
vector<pair<ll, pair<ll, ll>>> clan;

bool check(ll v){
	int i=0,j=0;
	while(j < clan.size() && i < dish.size()){
		if(dish[i].first < clan[j].first){
			v-=dish[i].second;
			++i;
			if(v < 0)return false;
		}
		else{
			if(clan[j].second.first <= v){
				v+=clan[j].second.second;
			}
			++j;
		}
	}
	while(i < dish.size()){
		v-=dish[i].second;
		++i;
		if(v < 0)return false;
	}
	return (v>=1);
}


void solve() {
    dish.clear();
    clan.clear();

    ll x;
    sc(x);

    int b;
    sc(b);

    ll req = 1;

    for(int i = 0;i < b;i++) {
        ll xi, yi;
        cin >> xi >> yi;
        dish.pb({xi, yi});
        req += yi;
    }

    int c;
    cin >> c;
    for(int i = 0;i < c;i++) {
        ll pi, qi, ri;
        cin >> pi >> qi >> ri;
        clan.pb(make_pair(pi, make_pair(qi, ri)));
    }

    srt(dish);
    srt(clan);

    ll l = 0, r = req, ans = r;
    while(l <= r) {
        ll m = l + (r - l) / 2;
        if(check(m)) {
            ans = min(ans, m);
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    pf(ans);
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