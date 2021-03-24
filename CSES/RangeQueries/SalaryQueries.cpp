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
const int MOD = 1e9 + 7;
const int N = 4e5 + 5;
/*-------------- Push your limits here ---------------------------*/
ll bit[N];
vector<int> arr;
int n, q;

void upd(int i, int val) {
    for(;i <= N;i += (i & (-i))) bit[i] += val;
}

void ad(int x, int b) {
    int ind = upper_bound(all(arr), x) - arr.begin();
    upd(ind, b);
}

ll sum(int x) {
    ll res = 0;
    for(;x;x -= (x & (-x))) {
        res += bit[x];
    }

    return res;
}

ll query(int x) {
    int ind = upper_bound(all(arr), x) - arr.begin();
    return sum(ind);
}

void solve() {
    cin >> n >> q;
    vector<int> vals(n);
    for(int i = 0;i < n;i++) cin >> vals[i];
    arr = vals;
    vector<array<int, 3>> rec;
    for(int i = 0;i < q;i++) {
        char t;
        int a, b;
        cin >> t >> a >> b;
        rec.push_back({t == '?', a, b});
        if(t == '!') arr.push_back(b);
    }

    sort(all(arr));
    arr.erase(unique(all(arr)), arr.end());
    for(int i = 0;i < n;i++) {
        ad(vals[i], 1);
    }

    for(auto u : rec) {
        u[1]--;
        if(u[0] == 0) {
            ad(vals[u[1]], -1);
            vals[u[1]] = u[2];
            ad(vals[u[1]], 1);
        } else {
            pf(query(u[2]) - query(u[1]));
        }
    
    }
}

int main() {
    go();
    ssolve
    return 0;
}
