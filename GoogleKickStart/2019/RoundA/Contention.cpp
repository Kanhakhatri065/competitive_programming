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
int n, q;
vector<pi> seg;
vector<int> val;

bool can(int x) {
    val.assign(sz(seg), 0);
    set<pi> s;
    int last = 0, cur = 0;

    for(auto pp : seg) {
        int l = pp.ff, r = pp.ss;
        while(!s.empty()) {
            auto it = s.begin();
            if(it->ff <= l) {
                val[it->ss] += max(it->ff - last, 0);
                ckmax(last, it->ff);
                s.erase(it);
            } else {
                break;
            }
        }

        if(last < l) {
            if(!s.empty()) {
                val[s.begin()->ss] += l - last;
            }
            last = l;
        }

        pi now = make_pair(r, cur++);
        s.insert(now);
        auto it = s.lower_bound(now);
        if(it == s.begin()) continue;
        it--;
        while(true) {
            if(val[it->ss] >= x) {
                if(it == s.begin()) {
                    s.erase(it);
                    break;
                } else {
                    auto bef = it;
                    it--;
                    s.erase(bef);
                }
            } else {
                break;
            }
        }
    }

    while(!s.empty()) {
        auto it = s.begin();
        val[it->ss] += max(it->ff - last, 0);
        ckmax(last, it->ff);
        s.erase(it);
    }

    bool res = true;
    int w = 0;
    for(int u : val) {
        if(u < x) {
            res = false;
        }
        w++;
    }

    return res;
}

void solve() {
    cin >> n >> q;
    seg.resize(q);
    int lo = 0, hi = n;
    for(int i = 0;i < q;i++) {
        int l, r;cin >> l >> r;
        l--;
        seg[i] = {l, r};
        ckmin(hi, r - l);
    }

    sort(all(seg));
    while(lo < hi) {
        int mid = (lo + hi + 1) >> 1;
        if(can(mid)) lo = mid;
        else hi =  mid - 1;
    }

    pf(hi);
}

int main() {
    go();
    mcsolve
    return 0;
}
