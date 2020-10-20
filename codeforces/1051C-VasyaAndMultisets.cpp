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
void solve() {
	int n;
	sc(n);

	vector<int> v(n);
	map<int, int> mp;
	for(int i = 0;i < n;i++) {
		sc(v[i]);
		mp[v[i]]++;
	}
	
	int single = 0;
	for(auto it : mp) {
		if(it.second == 1) {
			single++;
		}
	}

	if(single & 1) {
		bool flag = false;
		int t = 0;
		for(auto it : mp) {
			if(it.second > 2) {
				t = it.first;
				flag = true;
				break;
			}
		}

		if(flag) {
			string res = "";
			int c = 0, c_t = 0;
			for(int i = 0;i < n;i++) {
				if(mp[v[i]] == 1) {
					if(c < single / 2) {
						res += 'B';
					} else {
						res += 'A';
					}

					c++;
				} else {
					if(v[i] == t && c_t == 0) {
						res += 'B';
						c_t++;
					} else {
						res += 'A';
					}
				}
			}

			yes;
			pf(res);
		} else {
			no;
		}
	} else {
		int c = 0;
		string res = "";
		for(int i = 0;i < n;i++) {
			if(mp[v[i]] == 1) {
				if(c < single / 2) {
					res += 'A';
					c++;
				} else {
					res += 'B';
					c++;
				}
			} else {
				res += 'A';
			}
		}

		yes;
		pf(res);
	}
}

int main() {
	solve();
	return 0;
}
