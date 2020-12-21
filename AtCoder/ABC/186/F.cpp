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
const int N = 2e5 + 5;
/*-------------- Push your limits here ---------------------------*/
class Bit {
    vector<int> count;
public:
    Bit(const int size) : count(size, 0) {}
    void increment(int position) {
        while(position < sz(count)) {
            count[position]++;
            position += ~position & (position + 1);
        }
    }

    int get(int position) {
        int result = 0;
        while(position >= 0) {
            result += count[position];
            position -= ~position & (position + 1);
        }

        return result;
    }
};

void solve() {
    ll height, width, m;
    cin >> height >> width >> m;

    vector<pi> blocks(m);
    ll min_y = width, min_x = height;

    for(auto& it : blocks) {
        cin >> it.ff >> it.ss;
        it.ff--, it.ss--;

        if(it.ff == 0) min_y = min(min_y, (ll) it.ss);
        if(it.ss == 0) min_x = min(min_y, (ll) it.ff);
    }

    vector<bool> vertical(height, false), horizontal(width, false);

    sort(all(blocks), [&](pi a, pi b) {
        return a.ss == b.ss ? a.ff < b.ff : a.ss < b.ss;
    });

    Bit bit(height);

    ll result = height * width - (height - min_x) * (width - min_y);

    for(const auto it : blocks) {
        int x = it.ff, y = it.ss;

        if(x >= min_x && y >= min_y) continue;

        if(min_x > x && min_y > y) {
            if(!vertical[x] || !horizontal[y]) result--;
        
            if(!horizontal[y]) {
                const auto whole = bit.get(height - 1);
                const auto up = bit.get(x);
                result -= whole - up;
                result -= (height - min_x);
            }
        
            if(!vertical[x]) {
                bit.increment(x);
                result -= (width - min_y);
            }
        } else if(y >= min_y) {
            if(!vertical[x]) {
                result -= (width - y);
            }
        } else if(x >= min_x) {
            if(!horizontal[y]) {
                result -= (height - x);
            }
        }

        horizontal[y] = true;
        horizontal[x] = true;
    }

    pf(result);
}

int main() {
    go();
    ssolve
    return 0;
}
