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
map<int, int> ok, ban;
queue<int> q;
void solve() {
    int m, k;
    cin >> m >> k;

    vector<int> x(m + 1), d(m + 1);
    vector<int> status(m + 1);
    for(int i = 1;i <= m;i++) {
        cin >> x[i] >> d[i];
    }

    int entrusted = 0;
    for(int i = 0;i < k;i++) {
        int t, id;
        cin >> t >> id;

        int a = x[id] - d[id], b = x[id] + d[id];
        if(status[id] == 1) {
            ok[a]--;
            if(a != b) {
                ok[b]--;
            }
            entrusted--;
        } else if(status[id] == 2) {
            ban[a]--;
            ban[b]--;
        }

        status[id] = (t == 3 ? 0 : t);

        if(t == 1) {
            ok[a]++;
            if(a != b) {
                ok[b]++;
            }
            entrusted++;
            q.push(id);
        } else if(t == 2) {
            ban[a]++;
            ban[b]++;
        }

        int idx = -1;
        while(!q.empty()) {
            int c = q.front();
            if(status[c] == 1) {
                idx = c;
                break;
            }
            q.pop();
        }

        if(idx == -1) {
            pf(-1);
        } else {
            int a = x[idx] - d[idx], b = x[idx] + d[idx];
            vector<int> res;
            if(a > 0 && ok[a] == entrusted && ban[a] == 0) {
                res.pb(a);
            }

            if(b > a && ok[b] == entrusted && ban[b] == 0) {
                res.pb(b);
            }
            
            cout << int(res.size()) << ' ';
            for(auto it : res) {
                cout << it << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    go();
    solve();
    return 0;
}