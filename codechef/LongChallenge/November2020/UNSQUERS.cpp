#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m, s, a[N];

struct item {
	int val, ob;
	item *l, *r;

	item() {
		val = ob = 0;
		l = r = nullptr;
	}

	item(const item* other) {
		if(other == nullptr) {
			val = ob = 0;
			l = r = nullptr;
		} else {
			val = other->val;
			ob = other->ob;
			l = other->l;
			r = other->r;
		}
	}
};

void push(item* &v, int l, int r) {
	v->l = new item(v->l);
	v->r = new item(v->r);

	if(v->ob) {
		v->val += v->ob;
		if(l < r) {
			v->l->ob += v->ob;
			v->r->ob += v->ob;
		}
		v->ob = 0;
	}
}	

void update(item* &v, int l, int r, int tl, int tr) {
	push(v, l, r);
	if(l > r || tl > r || l > tr) {
		return;
	}

	if(tl <= l && r <= tr) {
		v->val++;
		v->l->ob++;
		v->r->ob++;
		return;
	}

	int mid = (r + l) >> 1;
	update(v->l, l, mid, tl, tr);
	update(v->r, mid + 1, r, tl, tr);
	v->val = max(v->l->val, v->r->val);
}

int get(item *v, int l, int r, int tl, int tr) {
	if(!v) return 0;
	push(v, l, r);
	if(l > r || tl > r || l > tr) {
		return 0;
	}

	if(tl <= l && r <= tr) {
		return v->val;
	}

	int mid = (r + l) >> 1;
	return max(get(v->l, l, mid, tl, tr), get(v->r, mid + 1, r, tl, tr));
}

item*rt[N];

void solve() {
	scanf("%d%d%d", &n, &m, &s);

	vector<int> st;
	st.push_back(0);
	a[0] = 1e9;
	rt[0] = new item();

	for(int i = 1;i <= n;i++) {
		scanf("%d", &a[i]);
		while(a[st.back()] < a[i]) {
			st.pop_back();
		}

		rt[i] = new item(rt[i - 1]);
		update(rt[i], 1, n, st.back() + 1, i);
		st.push_back(i);
	}

	int lst = 0;
	while(m--) {
		int x, y;
		scanf("%d%d", &x, &y);

		int l = (x + s * 1LL * lst - 1) % n + 1;
		int r = (y + s * 1LL * lst - 1) % n + 1;

		if(l > r) {
			swap(l, r);
		}

		lst = get(rt[r], 1, n, l, r);
		printf("%d\n", lst);
	}
}

int main() {
	solve();
	return 0;
}
