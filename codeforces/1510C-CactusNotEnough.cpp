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
vector<int> adj[N];
bool visited[N];
int cnt[N];
int n, m;

int main() {
    go();
    while(true) {
        cin >> n >> m;
        if(n == 0 && m == 0) {
            break;
        }

        fill(visited, visited + n + 1, false);
        fill(cnt, cnt + n + 1, 0);
        for(int i = 1;i <= n;i++) adj[i].clear();

        vector<vector<int>> single_component;
        vector<vector<int>> paths;
        int total_single = 0;
        for(int i = 0;i < m;i++) {
            int len;
            cin >> len;
            vector<int> store(len);
            for(int j = 0;j < len;j++) cin >> store[j];

            for(int j = 1;j < len;j++) {
                adj[store[j]].pb(store[j - 1]);
                adj[store[j - 1]].pb(store[j]);
                cnt[store[j]]++;
                cnt[store[j - 1]]++;
            }

            vector<int> tmp;
            for(int j = 0;j < len;j++) if(cnt[store[j]] == 1) tmp.pb(store[j]), total_single++;
            single_component.pb(tmp);
            paths.pb(store);
        }

        if(n == 1) {
            pf(0);
            continue;
        }

        vector<pi> ans;
        if(total_single == 2) {
            int f = -1;
            for(auto it : single_component) {
                for(auto itr : it) {
                    f = itr;
                    break;
                }
                if(f != -1) break;
            }

            int s = -1;
            for(auto it : single_component) {
                for(auto itr : it) {
                    if(itr != f) {
                        s = itr;
                        break;
                    }
                }

                if(s != -1) break;
            }

            ans.pb({f, s});
        }

        for(int i = 0;i < sz(single_component);i++) {
            if(sz(single_component[i]) == 1) {
                for(auto itr : paths[i]) {
                    if(cnt[itr] > 1) {
                        
                    }
                }
            }
        }
    }

    return 0;
}
