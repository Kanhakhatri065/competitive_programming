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
    string s;
    cin >> s;
    int n = sz(s);

    if(s == string(n, '1')) {
        pf(0);
        return;
    }

    if(s == string(n, '0')) {
        pf(1);
        return;
    }

    vector<array<int, 2>> right_nearest(n);
    int zero_pos = n, one_pos = n;
    for(int i = n - 1;i >= 0;i--) {
        if(s[i] == '1') one_pos = i;
        else zero_pos = i;

        right_nearest[i][0] = zero_pos;
        right_nearest[i][1] = one_pos;
    }

    vector<int> first_dp(n + 1, 0), second_dp(n + 1, 0);
    for(int i = n - 1;i >= 0;i--) {
        first_dp[i] = first_dp[i + 1];
        if(s[i] == '0' && right_nearest[i][1] < n) {
            ckmax(first_dp[i], first_dp[right_nearest[i][1] + 1] + 1);
        }

        if(s[i] == '1' && right_nearest[i][0] < n) {
            ckmax(first_dp[i], first_dp[right_nearest[i][0] + 1] + 1);
        }

        second_dp[i] = second_dp[i + 1];
        if(right_nearest[i][1] < n) {
            ckmax(second_dp[i], first_dp[right_nearest[i][1] + 1] + 1);
        }
    }

    /*
    cout << "First dp : ";
    vpnt(first_dp);
    cout << "Second dp : ";
    vpnt(second_dp);
    */

    int size = second_dp[0] + 1;
    int idx = right_nearest[0][1] + 1;
    string res = "1";
    for(int i = 1;i < size;i++) {
        if(idx >= n) {
            res += '0';
            continue;
        }

        if(right_nearest[idx][0] >= n) {
            res += '0';
            continue;
        }

        if(first_dp[right_nearest[idx][0] + 1] < size - i - 1) {
            res += '0';
            idx = right_nearest[idx][0] + 1;
        } else {
            res += '1';
            idx = right_nearest[idx][1] + 1;
        }
    }    

    pf(res);
}

int main() {
    go();
    msolve
    return 0;
}
