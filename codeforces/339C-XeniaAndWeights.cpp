/*
    I love the sound you make when you shut up.
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
/*----typedefs--------*/
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
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
const int N = 1002;
/*-------------- Push your limits here ---------------------------*/
int m;
vector<int> deltas;
vector<int> ans;
bool done = false;
void dfs(int balance = 0, int cur = 0, int depth = 0) {
    if(done) return;
    if(cur != 0) {
        ans.pb(cur);
    }

    if(depth == m) {
        done = true;
        return;
    }

    for(int del : deltas) {
        if(del == cur || abs(balance) >= del) continue;
        int newBal = (balance < 0) ? balance + del : balance - del;
        dfs(newBal, del, depth + 1);
    }

    if(done) return;
    if(cur != 0) {
        ans.pop_back();
    }
}
void solve() {
    string s;
    cin >> s;

    cin >> m;

    for(int i = 0;i < sz(s);i++) {
        if(s[i] == '1') {
            deltas.pb(i + 1);
        }
    }

    dfs(0, 0, 0);
    if(done) {
        yes;
        vpnt(ans);
    } else {
        no;
    }
}

int main() {
    go();
    ssolve
    return 0;
}
