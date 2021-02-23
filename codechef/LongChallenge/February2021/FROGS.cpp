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

    vector<int> v(n);
    map<int, int> jump;
    map<int, vector<int>> pos;
    for(int i= 0;i < n;i++) {
        cin >> v[i];
        pos[i].pb(v[i]);
    }

    for(int i = 0;i < n;i++) {
        int x;cin >> x;
        jump[v[i]] = x;
    }

    int cnt = 0;
    while(true) {
        bool flag = true;
        int val = 0;
        int idx = -1;
        vector<pi> store;
        for(auto it : pos) {
            for(auto itr : it.ss) {
                store.pb({it.ff, itr});
            }
        }

        for(int i = 0;i + 1 < n;i++) {
            if(store[i].ss > store[i + 1].ss) {
                flag = false;
                val = store[i].ss;
                idx = store[i].ff;
                break;
            } else {
                if(store[i].ff == store[i + 1].ff) {
                    flag = false;
                    val = store[i + 1].ss;
                    idx = store[i + 1].ff;
                    break;
                }
            }
        }

        if(flag) break;

        if(find(all(pos[idx]), val) != pos[idx].end()) {
            pos[idx].erase(find(all(pos[idx]), val));
        }

        if(pos[idx].empty()) {
            pos.erase(idx);
        }

        pos[idx + jump[val]].pb(val);
        cnt++;
    }

    pf(cnt);
}

int main() {
    go();
    msolve
    return 0;
}
