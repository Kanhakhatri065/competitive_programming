#include <bits/stdc++.h>

using namespace std;

struct FenwickTree {
	vector<int> bit;
	int n;

	FenwickTree(int n) {
		this->n = n;
		bit.assign(this->n, 0);
	}

	FenwickTree(vector<int> a) : FenwickTree(int(a.size())) {
		for(int i = 0;i < int(a.size());i++) {
			add(i, a[i]);
		}
	}

	int sum(int r) {
		int ret = 0;
		for(;r >= 0;r = (r & (r + 1)) - 1) {
			ret += bit[r];
		}

		return ret;
	}

	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}

	void add(int idx, int delta) {
		for(;idx < n;idx = idx | (idx + 1)) {
			bit[idx] += delta;
		}
	}
};

int main() {
	vector<int> a({1, 2, 3, 4, 5});
	FenwickTree fenwicktree(a);

	cout << "sum from 1 to 4 : " <<  fenwicktree.sum(1, 4) << endl;

	return 0;
}
