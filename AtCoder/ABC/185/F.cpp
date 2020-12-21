/*
    I love the sound you make when you shut up.
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
/*----typedefs--------*/
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
}
/*-------- movement in a 2D array ------*/
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
/*--------test-case stuff---------------*/
#define ssolve solve();
#define msolve int t;cin >> t;while(t--) {solve();}
#define mcsolve int t;cin >> t;for(int tt = 1;tt <= t;tt++) {cout << "Case #" << tt << ": ";solve();}
/*----------------------------------------------------------------*/
const int MOD = 1e9 + 7;
const int N = 3e5 + 5;
/*-------------- Push your limits here ---------------------------*/
struct FenwickTree {
    //use 0-index while passing argument for range function
    vector<int> bit_tree;

    int get(int index) {
        int ans = 0;
        index++;

        while(index > 0) {
            ans ^= bit_tree[index];
            index -= index & (-index);
        }

        return ans;
    }

public:
    void update(int index, int val) {
        index++;
        while(index < sz(bit_tree)) {
            bit_tree[index] ^= val;
            index += index & (-index);
        }
    }

    FenwickTree(vector<int> arr, int n) {
        bit_tree.assign(n + 1, 0);

        for(int i = 0;i < n;i++) {
            update(i, arr[i]);
        }
    }

    int range(int l, int r) {
        return get(r) ^ get(l - 1);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    forIn(v, n);

    FenwickTree fenwicktree(v, n);

    while(q--) {
        int t, x, y;
        cin >> t >> x >> y;

        if(t == 1) {
            x--;
            fenwicktree.update(x, y);
        } else {
            x--, y--;
            pf(fenwicktree.range(x, y));
        }
    }    
}

int main() {
    go();
    ssolve
    return 0;
}
