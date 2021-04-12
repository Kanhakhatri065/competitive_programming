/*
    I love the sound you make when you shut up.
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
/*-------typedefs------*/
template<class T> using ordered_set = tree<T, null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update> ;
using ll = long long;
using pi = pair<int, int>;
/*-----in and out--------*/
#define pf(a) cout << a << endl
#define forIn(arr, num) for(int i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(int i = 0; i < int(ans.size()); i++) cout << ans[i] << (i + 1 < int(ans.size()) ? ' ' : '\n');
/*---useful defines------*/
#define sz(x) (int)(x).size()
#define pb push_back
#define mem(a, b) memset(a,(b), sizeof(a))
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
/*----- the binary answer of life-----*/
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
/*---checking and pushing-----*/
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
/*---- FAST I/O and file read ---*/
void go() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
}
/*-------- test-case stuff--------------*/
#define ssolve solve();
#define msolve int T;cin >> T;while(T--) {solve();}
#define mcsolve int T;cin >> T;for(int tt = 1;tt <= T;tt++) {cout << "Case #" << tt << ": ";solve();}
/*-------- movement in a 2D array ------*/
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
/*----------------------------------------------------------------*/
const ll INF = 2e18;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
/*-------------- Push your limits here ---------------------------*/
struct items {
    int x, y, v;
    bool operator < (const items &oth) const {
        return y < oth.y;
    }
};

struct SegmentTree {
    int n;
    vector<ll> st;
    vector<ll> lazy;

    SegmentTree(int n) : n(n), st(n * 4, -INF), lazy(4 * n) {}
    SegmentTree() {}

    void change(ll v, ll id) {
        st[id] += v;
        lazy[id] += v;
    }

    void push(ll id) {
        change(lazy[id], id << 1);
        change(lazy[id], id << 1 | 1);
        lazy[id] = 0;
    }

    void update(int L, int R, ll v, int id, int l, int r) {
        if(R < l || r < L) return;
        if(L <= l && r <= R) {
            change(v, id);
            return;
        }

        push(id);
        int mid = (l + r) >> 1;
        update(L, R, v, id << 1, l, mid);
        update(L, R, v, id << 1 | 1, mid + 1, r);
        st[id] = max(st[id << 1], st[id << 1 | 1]);
    }

    void update(int L, int R, ll v) {
        update(L, R, v, 1, 0, n);
    }
};

int n, m, k;
items a[N];
vector<int> vals;
SegmentTree st;
void solve() {
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].x >> a[i].y >> a[i].v;
        vals.pb(a[i].x);
        vals.pb(a[i].y);
    }

    sort(all(vals));
    vals.resize(unique(all(vals)) - vals.begin());
    m = sz(vals);

    sort(a + 1, a + n + 1);
    st = SegmentTree(m);
    
    ll ans = 0;
    int cur = 0;
    for(int r = 0;r < m;r++) {
        st.update(r, r, INF + 1LL * k * vals[r]);
        while(cur + 1 <= n && a[cur + 1].y <= vals[r]) {
            cur++;
            if(a[cur].v > 0) {
                int id = lower_bound(all(vals), a[cur].x) - vals.begin();
                st.update(0, id, a[cur].v);
            }
        }
        ckmax(ans, st.st[1] - 1LL * k * vals[r]);
    }

    pf(ans);
}

int main() {
    go();
    ssolve
    return 0;
}
