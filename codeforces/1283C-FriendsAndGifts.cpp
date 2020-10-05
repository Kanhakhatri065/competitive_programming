/*** I came, I saw, I conquered. ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef unsigned long long ull;
#define sc(a) cin >> a
#define pf(a) cout << a << endl
#define forIn(arr, num) for(ll i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
#define mod 1000000007
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
void go() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
/*----------------------------------------------------------------*/
void solve() {
    int n;
    sc(n);

    vector<int> f(n), in(n), out(n);
    for(int i = 0;i < n;i++) {
        sc(f[i]);
        f[i]--;
        if(f[i] != -1) {
            out[i]++;
            in[f[i]]++;   
        }
    }

    vector<int> loops;
    for(int i = 0;i < n;i++) {
        if(in[i] == 0 && out[i] == 0) {
            loops.pb(i);
        }
    }

    if(int(loops.size()) == 1) {
        int idx = loops[0];
        for(int i = 0;i < n;i++) {
            if(in[i] == 0 && i != idx) {
                f[idx] = i;
                out[idx]++;
                in[i]++;
                break;
            }
        }
    } else if(int(loops.size()) > 1) {
        for(int i = 0;i < int(loops.size());i++) {
            int cur = loops[i];
            int nxt = loops[(i + 1) % int(loops.size())];
            f[cur] = nxt;
            out[cur]++;
            in[nxt]++;
        }
    }

    loops.clear();
    vector<int> ins, outs;
    for(int i = 0;i < n;i++) {
        if(in[i] == 0) {
            ins.pb(i);
        }

        if(out[i] == 0) {
            outs.pb(i);
        }
    }

    for(int i = 0;i < int(outs.size());i++) {
        f[outs[i]] = ins[i];
    }

    for(int i = 0;i < n;i++) {
        cout << (f[i] + 1) << " ";
    }
    cout << endl;
}

int main() {
    go();
    solve();
    return 0;
}