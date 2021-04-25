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
#define int long long

set<int> s1;
map<int, int> le, ri, co;
int prob;

void remove(int x) {
    if(co[x] == 0) {
        auto itr = s1.lower_bound(x);
        s1.erase(x);
        int l = -1, r = -1;
        itr = s1.lower_bound(x);

        if(itr != s1.end()) {
            r = *itr;
        }

        if(itr != s1.begin()) {
            itr--;
            l = *itr;
        }

        if(l != -1 && ri[l] > le[x]) prob--;
        if(r != -1 && ri[x] > le[r]) prob--;
        if(l != -1 && r != -1 && ri[l] > le[r]) prob++;
    }
    co[x]++;
}

void add(int x) {
    co[x]--;
    if(co[x] == 0) {
        auto itr = s1.lower_bound(x);
        int l = -1, r = -1;
        
        if(itr != s1.end()) r = *itr;
        if(itr != s1.begin()) {
            itr--;
            l = *itr;
        }

        if(l != -1 && ri[l] > le[x]) prob++;
        if(r != -1 && ri[x] > le[r]) prob++;
        if(l != -1 && r != -1 && ri[l] > le[r]) prob--;
        s1.insert(x);
    }
}

void solve() {
    int n;
    cin >> n;

    s1.clear();
    le.clear();
    co.clear();
    ri.clear();

    vector<int> a(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        s1.insert(a[i]);
        if(!le.count(a[i])) le[a[i]]= i;
        ri[a[i]] = i;
    }

    ll ans = 0;
    prob = 0;

    for(auto itr  = s1.begin();itr != s1.end();itr++) {
        if(itr != s1.begin()) {
            auto ptr = --itr;
            itr++;
            if(ri[*ptr] > le[*itr]) {
                prob++;
            }
        }
    }

    if(prob == 0) {
        int temp = n * (n + 1);
        temp /= 2;
        pf(temp);
        return;
    }

    int r = 0;
    for(int l = 0;l < n;l++) {
        while(prob > 0 && r < n) {
            remove(a[r]);
            r++;
        }

        if(prob == 0) ans += (n + 1 - r);
        add(a[l]);
    }

    pf(ans);
}

int32_t main() {
    go();
    msolve
    return 0;
}
