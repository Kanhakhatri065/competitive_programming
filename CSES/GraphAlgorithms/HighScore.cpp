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
const int MOD = 1e9 + 7;
const int N = 2505;
const int M = 5005;
const ll INF = 1LL << 62;
/*-------------- Push your limits here ---------------------------*/
struct Edge {
    int a, b, w;
    int s() {
        return a < b ? a : -a;
    }
};

struct Node {
    ll dist = INF;
    int prev = -1;
};

int n, m;
vector<Node> nodes;
vector<Edge> edges;

void BellmanFord() {
    nodes[1].dist = 0;
    sort(all(edges), [&](auto a, auto b) {
        return a.s() < b.s();
    });

    int lim = (n + 1) / 2 + 2;
    for(int i = 0;i < lim;i++) {
        for(auto edge : edges) {
            Node cur = nodes[edge.a], &dest = nodes[edge.b];
            if(abs(cur.dist) == INF) continue;
            ll d = cur.dist + edge.w;
            if(d < dest.dist) {
                dest.prev = edge.a;
                dest.dist = (i < lim - 1 ? d : -INF);
            }
        }
    }

    for(int i = 0;i < lim;i++) {
        for(auto edge : edges) {
            if(nodes[edge.a].dist == -INF) {
                nodes[edge.b].dist = -INF;
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    nodes.resize(n + 1);
    edges.resize(m);

    for(int i = 0;i < m;i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
        edges[i].w *= -1;
    }

    BellmanFord();
    if(nodes[n].dist == -INF) {
        pf(-1);
    } else {
        pf(-nodes[n].dist);
    }
}

int main() {
    go();
    ssolve
    return 0;
}
