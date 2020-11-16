#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
pair<ll, ll> numSolve(vector<int> &v, int cap) {
	ll buy = 0;
	ll at = 0;
	for(int out : v) {
		if(out < cap) {
			continue;
		}

		buy += (out - cap);
		if(cap) {
			at++;
		}
	}

	return {buy, at};
}

const int MOD = 1e9 + 7;
ll tri(ll n) {
	return n * (n + 1LL) / 2;
}

ll sumof(ll a, ll b) {
	if(a > b) return 0;
	ll ret = tri(b) - tri(a - 1);
	ret %= MOD;
	if(ret < 0) {
		ret += MOD;
	}

	return ret;
}


class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
		ll lhs = 0;
		ll rhs = 2e9;
		
		while(lhs < rhs) {
			ll mid = (lhs + rhs + 1) / 2;
			pair<ll, ll> key = numSolve(inventory, mid);
			if(key.first + key.second >= orders) lhs = mid;
			else rhs = mid - 1;
		}		

		ll ret = 0;
		for(int &out : inventory) {
			if(out <= lhs) continue;
			int numspent = out - lhs;
			orders -= numspent;
			ret += sumof(lhs + 1, out);
			ret %= MOD;
			out = lhs;
		}

		for(int &out : inventory) {
			if(orders == 0) {
				break;
			}

			if(out == lhs) {
				ret += out;
				ret %= MOD;
				orders--;
			}
		}

		return ret;
    }
};


