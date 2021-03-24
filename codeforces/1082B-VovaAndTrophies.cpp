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
const int N = 2e5 + 5;
/*-------------- Push your limits here ---------------------------*/
void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<pi> store;
    int cnt = 0, l = 0, r = 0;
    for(int i = 0;i < n;i++) {
        if(s[i] == 'G') {
            if(cnt > 0) {
                cnt++;
                r = i;
            } else {
                cnt = 1;
                l = r = i;
            }
        } else {
            if(cnt > 0) {
                store.pb({l, r});
            }
            cnt = 0;
        }
    }

    if(cnt > 0) store.pb({l, r});

    if(sz(store) == 0) {
        pf(0);
    } else if(sz(store) == 1) {
        pf(store[0].ss - store[0].ff + 1);
    } else if(sz(store) == 2) {
        if(store[1].ff - store[0].ss == 2) {
            pf((store[1].ss - store[1].ff + 1) + (store[0].ss - store[0].ff + 1));
        } else {
            int mx = max((store[1].ss - store[1].ff + 1), (store[0].ss - store[0].ff + 1));
            pf(mx + 1);
        }
    } else {
        int mx = 0;
        for(int i = 0;i < sz(store);i++) {
            if(i + 1 < n) {
                if(store[i + 1].ff - store[i].ss == 2) {
                    int cnt = (store[i + 1].ss - store[i + 1].ff + 1) + (store[i].ss - store[i].ff + 1);
                    cnt++;
                    ckmax(mx, cnt);
                }
            }

            ckmax(mx, store[i].ss - store[i].ff + 2);
        }

        pf(mx);
    }
}

int main() {
    go();
    ssolve
    return 0;
}
