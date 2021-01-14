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
const int N = 2e5 + 5;
/*-------------- Push your limits here ---------------------------*/
class Node {
public:
    int buy;
    int sell;

    Node() {}
    Node(int buy, int sell) {
        this->buy = buy;
        this->sell = sell;
    }
};

class Edge {
public:
    int from;
    int to;
    Edge() {}
    Edge(int from, int to) {
        this->from = from;
        this->to = to;
    }
};

bool has_smaller_from(const Edge& a, const Edge& b) {
    return a.from < b.from;
}

void solve() {
    int nnode, nedge;
    cin >> nnode >> nedge;

    vector<Node> node(nnode);
    for(int i = 0;i < nnode;i++) {
        int tmp;
        cin >> tmp;

        node.at(i).buy = tmp;
        node.at(i).sell = tmp;
    }

    vector<Edge> edge(nedge);
    for(int i = 0;i < nedge;i++) {
        int from, to;
        cin >> from >> to;

        from--, to--;
        edge.at(i).from = from;
        edge.at(i).to = to;
    }

    sort(all(edge), has_smaller_from);
    int res = -2e9;

    for(const auto & e : edge) {
        res = max(res, node.at(e.to).sell - node.at(e.from).buy);
        node.at(e.to).buy = min(node.at(e.to).buy, node.at(e.from).buy);
    }

    pf(res);
}

int main() {
    //go();
    ssolve
    return 0;
}
