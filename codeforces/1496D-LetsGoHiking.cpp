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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
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
const int N = 1e5 + 5;
/*-------------- Push your limits here ---------------------------*/
int p[N], d[N];
void solve() {
    int n;
    cin >> n;

    for(int i = 1;i <= n;i++) {
        cin >> p[i];
    }

    for(int i = 2;i <= n;i++) {
        d[i] = (p[i - 1] < p[i]);
    }

    int mx = 0, cnt = 0;
    for(int l = 2, r = 2;l <= n;l = r = r + 1) {
        int o = d[l];
        while(r + 1 <= n && o == d[r + 1]) r++;
        int len = r - l + 2;
        if(len > mx) {
            mx = len;
            cnt = 1;
        } else if(len == mx) {
            cnt++;
        }
    }

    if(cnt != 2 || (mx & 1) == 0) {
        pf(0);
        return;
    }

    bool flag = false;
    for(int i = 3;i <= n && !flag;i++) {
        if(d[i - 1] && !d[i]) {
            int l = i - 1, r = i;
            while(l > 2 && d[l - 1]) l--;
            while(r < n && !d[r + 1]) r++;
            if((i - 1) - (l - 1) + 1 == mx && r - (i - 1) + 1 == mx) {
                flag = true;
            }
        }
    }

    if(flag) {
        pf(1);
    } else {
        pf(0);
    }
}

int main() {
    go();
    ssolve
    return 0;
}
