class DSU {
public:
	vector<int> par;
	vector<int> rnk;

	DSU(int n) {
		par.assign(n, 0);
		rnk.assign(n, 0);
		for(int i = 0;i <= n;i++) {
			par[i] = i;
		}
	}

	int find(int x) {
		return par[x] == x ? par[x] = find(par[x]);
	}

	void union_set(int a, int b) {
		a = find(a), b = find(b);
		if(a != b) {
			if(rnk[a] < rnk[b]) swap(a, b);

			par[b] = a;
			if(rnk[a] == rnk[b]) rnk[a]++;
		}
	}
};
