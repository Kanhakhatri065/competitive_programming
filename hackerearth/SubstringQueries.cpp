/*** I came, I saw, I conquered. ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef unsigned long long ull;
#define sc(a) cin >> a
#define pf(a) cout << a << endl
#define forIn(arr, num) for(ll i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
#define mod 1000000007
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
void go() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
/*----------------------------------------------------------------*/
int n;
string a;
int cnt[62];
ll ONE = 1;
inline int val(char c) {
	if(c >= 'a') return 10 + 26 + c - 'a';
	if(c >= 'A') return 10 + c - 'A';
	else return c - '0';
}

ll find_ans(ll mask) {
	int st = 0, en = 0;
	ll run = 0;
	ll ans = 0;
	memset(cnt, 0, sizeof cnt);
	while(en < n and st < n) {
		int added = val(a[en]);
		cnt[added]++;
		if(cnt[added] == 1) run |= ONE << added;
		while(st < n and ((run & mask) == mask)) {			
			ans += n - en;
			int sub = val(a[st]);
			cnt[sub]--;
			if(cnt[sub] == 0) run ^= ONE << sub;
			st++;	
		}
		en++;
	}
	return ans;
}

void solve() {
    sc(a);
    n = int(a.size());

	int q;
	sc(q);
	while(q--) {
		ll mask = 0;
		string qstr;
		cin >> qstr;
		int len = qstr.length();
		for (int i = 0; i < len; ++i) {
			mask |= ONE << val(qstr[i]);
		}
		printf("%lld\n", find_ans(mask));
	}	
}

int main() {
    go();
    
	int t;
	sc(t);
	for(int TEST_NO = 1; TEST_NO <= t; TEST_NO ++) {
		solve();
	}

	return 0;
}