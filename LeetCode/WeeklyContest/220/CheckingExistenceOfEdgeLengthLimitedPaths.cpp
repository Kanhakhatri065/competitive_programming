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
const int N = 1e5 + 5;
/*-------------- Push your limits here ---------------------------*/
int par[N];

int find(int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
}

void merge(int x, int y) {
    par[find(x)] = find(y);
}

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        for(int i = 0;i <= n;i++) par[i] = i;
        vector<bool> res(sz(queries));

        vector<array<int, 3>> edges;
        for(auto out : edgeList) {
            edges.pb({out[2], out[0], out[1]});
        }

        vector<array<int, 4>> qs;

        for(int i = 0;i < sz(queries);i++) {
            vector<int> &out = queries[i];
            qs.pb({out[2], out[0], out[1], i});
        }

        sort(all(edges));
        sort(all(qs));

        int i = 0, j = 0;

        while(j < sz(qs)) {
            while(i < sz(edges) && edges[i][0] < qs[j][0]) {
                merge(edges[i][1], edges[i][2]);
                i++;
            }

            if(find(qs[j][1]) == find(qs[j][2])) {
                res[qs[j][3]] = true;
            }

            j++;
        }

        return res;
    }
};