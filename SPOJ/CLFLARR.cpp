#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pf(a) cout << a << endl
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
void go() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
}
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int par[N], ans[N];
struct query {
    int l, r, c;
};

query queries[N];

void make_set(int v) {
    par[v] = v;
}

int find_set(int v) {
    return par[v] == v ? v : par[v] = find_set(par[v]); 
}


void solve() {
    int n, q;
    cin >> n >> q;

    fill(ans, ans + n + 1, 0);
    for(int i = 0;i <= n;i++) {
        make_set(i);
    }

    for(int i = 0;i < q;i++) {
        int l, r, c;
        cin >> l >> r >> c;
        l--, r--;
        queries[i] = {l, r, c};
    }

    for(int i = q - 1;i >= 0;i--) {
        int l = queries[i].l, r = queries[i].r, c = queries[i].c;
        for(int v = find_set(l);v <= r;v = find_set(v)) {
            ans[v] = c;
            par[v] = v + 1;
        }
    }

    for(int i = 0;i < n;i++) pf(ans[i]); 
}

int main() {
    go();
    int t;t = 1;
    while(t--) solve();
    return 0;
}
