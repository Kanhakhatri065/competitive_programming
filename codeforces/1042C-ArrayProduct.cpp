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
void solve() {
    int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	
	int cntneg = 0;
	int cntzero = 0;
	vector<int> used(n);
	int pos = -1;
	for (int i = 0; i < n; ++i) {
		if (a[i] == 0) {
			used[i] = 1;
			++cntzero;
		}
		if (a[i] < 0) {
			++cntneg;
			if (pos == -1 || abs(a[pos]) > abs(a[i]))
				pos = i;
		}
	}
	if (cntneg & 1)
		used[pos] = 1;
		
	if (cntzero == n || (cntzero == n - 1 && cntneg == 1)) {
		for (int i = 0; i < n - 1; ++i)
			printf("1 %d %d\n", i + 1, i + 2);
		return;
	}
	
	int lst = -1;
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			if (lst != -1) printf("1 %d %d\n", lst + 1, i + 1);
			lst = i;
		}
	}
	if (lst != -1) printf("2 %d\n", lst + 1);
	
	lst = -1;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			if (lst != -1) printf("1 %d %d\n", lst + 1, i + 1);
			lst = i;
		}
	}
}

int main() {
    FAST_IO
    solve();
    return 0;
}