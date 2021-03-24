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
    int r, g, b;
    cin >> r >> g >> b;
    
    vector<int> red(r), green(g), blue(b);
    forIn(red, r);
    forIn(green, g);
    forIn(blue, b);

    sort(all(red));
    sort(all(green));
    sort(all(blue));

    ll ans = -1;
    for(int i = 0;i < r;i++) {
        int x, y, z;
        x = red[i];

        if(x < green.front()) y = green.front();
        else if(x > green.back()) y = green.back();
        else {
            auto it = lower_bound(all(green), x);
            int mn = abs(*it - x);
            y = *it;
            if(it + 1 != green.end()) {
                auto itr = it + 1;
                if(mn > abs(*itr - x)) {
                    mn = abs(*itr - x);
                    y = *itr;
                }
            }

            if(it != green.begin()) {
                auto itr = it - 1;
                if(mn > abs(*itr - x)) {
                    y = *itr;
                }
            }
        }

        if(x < blue.front()) z = blue.front();
        else if(x > blue.back()) z = blue.back();
        else {
            auto it = lower_bound(all(blue), x);
            int mn = abs(*it - x);
            z = *it;
            if(it + 1 != blue.end()) {
                auto itr = it + 1;
                if(mn > abs(*itr - x)) {
                    mn = abs(*itr - x);
                    z = *itr;
                }
            }

            if(it != blue.begin()) {
                auto itr = it - 1;
                if(mn > abs(*itr - x)) {
                    z = *itr;
                }
            }
        }

        ll cnt = 1LL * (x - y) * (x - y) + 1LL * (y - z) * (y - z) + 1LL * (x - z) * (x - z);
        if(ans == -1) ans = cnt;
        else ckmin(ans, cnt);
    }

    for(int i = 0;i < g;i++) {
        int x, y, z;
        x = green[i];

        if(x < red.front()) y = red.front();
        else if(x > red.back()) y = red.back();
        else {
            auto it = lower_bound(all(red), x);
            int mn = abs(*it - x);
            y = *it;
            if(it + 1 != red.end()) {
                auto itr = it + 1;
                if(mn > abs(*itr - x)) {
                    mn = abs(*itr - x);
                    y = *itr;
                }
            }

            if(it != red.begin()) {
                auto itr = it - 1;
                if(mn > abs(*itr - x)) {
                    y = *itr;
                }
            }
        }

        if(x < blue.front()) z = blue.front();
        else if(x > blue.back()) z = blue.back();
        else {
            auto it = lower_bound(all(blue), x);
            int mn = abs(*it - x);
            z = *it;
            if(it + 1 != blue.end()) {
                auto itr = it + 1;
                if(mn > abs(*itr - x)) {
                    mn = abs(*itr - x);
                    z = *itr;
                }
            }

            if(it != blue.begin()) {
                auto itr = it - 1;
                if(mn > abs(*itr - x)) {
                    z = *itr;
                }
            }
        }

        ll cnt = 1LL * (x - y) * (x - y) + 1LL * (y - z) * (y - z) + 1LL * (x - z) * (x - z);
        if(ans == -1) ans = cnt;
        else ckmin(ans, cnt);
    }

    for(int i = 0;i < b;i++) {
        int x, y, z;
        x = blue[i];

        if(x < red.front()) y = red.front();
        else if(x > red.back()) y = red.back();
        else {
            auto it = lower_bound(all(red), x);
            int mn = abs(*it - x);
            y = *it;
            if(it + 1 != red.end()) {
                auto itr = it + 1;
                if(mn > abs(*itr - x)) {
                    mn = abs(*itr - x);
                    y = *itr;
                }
            }

            if(it != red.begin()) {
                auto itr = it - 1;
                if(mn > abs(*itr - x)) {
                    y = *itr;
                }
            }
        }

        if(x < green.front()) z = green.front();
        else if(x > green.back()) z = green.back();
        else {
            auto it = lower_bound(all(green), x);
            int mn = abs(*it - x);
            z = *it;
            if(it + 1 != green.end()) {
                auto itr = it + 1;
                if(mn > abs(*itr - x)) {
                    mn = abs(*itr - x);
                    z = *itr;
                }
            }

            if(it != green.begin()) {
                auto itr = it - 1;
                if(mn > abs(*itr - x)) {
                    z = *itr;
                }
            }
        }

        ll cnt = 1LL * (x - y) * (x - y) + 1LL * (y - z) * (y - z) + 1LL * (x - z) * (x - z);
        if(ans == -1) ans = cnt;
        else ckmin(ans, cnt);
    }

    pf(ans);
}

int main() {
    go();
    msolve
    return 0;
}
