#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pf(a) cout << a << endl
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
void go() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
}
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update> ;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
    map<int, ordered_set<int>> add;
    map<int, ordered_set<int>> sub;
    
    int n;
    cin >> n;

    for(int i = 0;i < n;i++) {
        int type, t, x;
        cin >> type >> t >> x;

        if(type == 1) {
            add[x].insert(t);
        } else if(type == 2) {
            sub[x].insert(t);
        } else {
            int ans = add[x].order_of_key(t);
            ans -= sub[x].order_of_key(t);
            pf(ans);
        }
    }
}

int main() {
    go();
    int t;t = 1;
    while(t--) solve();
    return 0;
}
