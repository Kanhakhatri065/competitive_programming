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
const int N = 2e5 + 5;
/*-------------- Push your limits here ---------------------------*/
void solve() {
    int n;
    cin >> n;

    string s;cin >> s;
    string a = "", b = "";
    for(int i = 0;i < n;i++) a += s[i];
    for(int i = n;i < 2 * n;i++) b += s[i];

    bool flip = false;
    int q;cin >> q;
    while(q--) {
        int type, c, d;cin >> type >> c >> d;
        if(type == 1) {
            c--, d--;
            if(flip) {
                if(c < n && d < n) {
                    swap(b[c], b[d]);
                } else if(c >= n && d < n) {
                    int tmp = b[d];
                    b[d] = a[c - n];
                    a[c - n] = tmp;
                } else if(c < n && d >= n) {
                    int tmp = b[c];
                    b[c] = a[d - n];
                    a[d - n] = tmp;
                } else {
                    swap(a[c - n], a[d - n]);
                }
            } else {
                if(c < n && d < n) {
                    swap(a[c], a[d]);
                } else if(c >= n && d < n) {
                    int tmp = a[d];
                    a[d] = b[c - n];
                    b[c - n] = tmp;
                } else if(c < n && d >= n) {
                    int tmp = a[c];
                    a[c] = b[d - n];
                    b[d - n] = tmp;
                } else {
                    swap(b[c - n], b[d - n]);
                }
            }
        } else {
            flip = !flip;
        }
    }

    if(flip) s = b + a;
    else s = a + b;

    pf(s);
}

int main() {
    go();
    ssolve
    return 0;
}
