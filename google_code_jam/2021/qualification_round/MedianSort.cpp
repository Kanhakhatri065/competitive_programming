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
int n, q;
int ask(int a, int b, int c) {
    cout << (a + 1) << " " << (b + 1) << " " << (c + 1) << endl;
    int res;cin >> res;
    if(res == -1) exit(0);
    return (res - 1);
}

void solve() {
    vector<int> ord = {0, 1};
    for(int j = 2;j < n;j++) {
        int s = 0;
        int e = sz(ord) + 1;
        while(s + 1 < e) {
            int m1 = (s + s + e) / 3;
            int m2 = (s + e + e) / 3;
            if(m1 == 0) m1++;
            while(m2 <= m1) m2++;
            if(m2 == sz(ord) + 1) m2--;
            while(m1 >= m2) m1--;

            int res = ask(j, ord[m1 - 1], ord[m2 - 1]);
            if(res == j) {
                ckmax(s, m1);
                ckmin(e, m2);
            } else if(res == ord[m1 - 1]) {
                ckmin(e, m1);
            } else if(res == ord[m2 - 1]) {
                ckmax(s, m2);
            }
        }

        ord.insert(ord.begin() + s, j);
    }

    for(auto x : ord) cout << (x + 1) << " ";
    cout << endl;

    int verdict;cin >> verdict;
    if(verdict == -1) exit(0);
}

int main() {
    int t;
    cin >> t >> n >> q;
    while(t--) solve();
    return 0;
}
