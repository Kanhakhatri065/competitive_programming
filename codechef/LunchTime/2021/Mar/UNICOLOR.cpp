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
}
/*-------- test-case stuff--------------*/
#define ssolve solve();
#define msolve int T;cin >> T;while(T--) {solve();}
#define mcsolve int T;cin >> T;for(int tt = 1;tt <= T;tt++) {cout << "Case #" << tt << ": ";solve();}
/*-------- movement in a 2D array ------*/
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
/*----------------------------------------------------------------*/
#define int long long
const int MOD = 998244353;
const int N = 1e5 + 5;
/*-------------- Push your limits here ---------------------------*/
struct state{
    int location, type, club;
    bool operator < (const state & t)const{
        if(location == t.location && type == t.type) return club < t.club;
        if(location == t.location) return type < t.type;
        return location < t.location;
    }
};

int c, m, n;
vector<state> a;
vector<int> adj[N];
int num[N];
int check[N];
int connected_components;
int Pow(int x, int y){
    if(y == 0)return 1;
    int k = Pow(x, y / 2);
    if(y % 2 == 1)return k * k % MOD * x % MOD;
    return k * k % MOD;
}
void dfs(int x){
    check[x] = 1;
    for(int u: adj[x]){
        if(check[u])continue;
        dfs(u);
    }
}

void reset(){
    a.clear();
    connected_components = 0;
    for(int i = 1; i <= c; i++){
        adj[i].clear();
        check[i] = 0;
    }
}

void solve() {
        cin >> c >> n >> m;
        for(int i = 1; i <= c; i++){
            cin >> num[i];
            for(int j = 1; j <= num[i]; j++){
                int l, r;
                cin >> l >> r;
                a.push_back({l, 0, i});
                a.push_back({r, 1, i});
            }
        }
        sort(a.begin(), a.end());
        set<int> s;
        int clubless = n;
        int L = 0;
        int R = 0;
        for(state u: a){
            if(u.type == 0){
                if(s.empty()){
                    L = u.location;
                }
                s.insert(u.club);
            }
            else{
                s.erase(s.find(u.club));
                if(!s.empty()){
                    int current_club = u.club;
                    int other_club = *s.begin();
                    adj[current_club].push_back(other_club);
                    adj[other_club].push_back(current_club);
                }
                if(s.empty()){
                    R = u.location;
                    clubless -= (R - L + 1);
                }
            }
        }
        for(int i = 1; i <= c; i++){
            if(!check[i]){
                connected_components++;
                dfs(i);
            }
        }
        connected_components += clubless;
        int ans = Pow(m, connected_components);
        cout << ans << '\n';
        reset();
}

int32_t main() {
    go();
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
