/*
    I love the sound you make when you shut up.
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
/*----typedefs--------*/
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef long long ll;typedef pair<int, int> pi;typedef pair<long long, long long> pl;
typedef vector<int> vi;typedef vector<pair<int, int>> vpi;typedef vector<long long> vl;typedef vector<vector<int>> vvi;
typedef map<int, int> mi;typedef map<long long, long long> ml;typedef map<int, vector<int>> mivi;
typedef set<int> si;typedef set<long long> sl;typedef set<pair<int, int>> spi;
typedef queue<int> qi;typedef queue<pair<int, int>> qpi;
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
/*--- bit-stuff ----*/
#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
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
/*----------------------------------------------------------------*/
const int MOD = 1e9 + 7;
const int N = 3e5 + 5;
const int MAX = 5005;
/*-------------- Push your limits here ---------------------------*/
vi adj[MAX];
void solve() {
    int n;
    scanf("%d", &n);

    n *= 2;

    for(int i = 0;i < n;i++) {
        int x;
        scanf("%d", &x);

        adj[x].pb(i + 1);
    }

    bool flag = true;
    for(int i = 1;i <= 5000;i++) {
        if(sz(adj[i]) % 2 == 1) {
            flag = false;;
            break;
        }
    }

    if(!flag) {
        pf(-1);
        return;
    }

    for(int i = 1;i <= 5e3;i++) {
        for(int j = 0;j < sz(adj[i]);j += 2) {
            printf("%d %d\n", adj[i][j], adj[i][j + 1]);
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    solve();
    return 0;
}