/*
    I love the sound you make when you shut up.
*/
#include <bits/stdc++.h>
using namespace std;
/*----typedefs--------*/
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
#define all(x) (x).begin(), (x).end()
void go() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
}
void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    forIn(v, n);

    vector<int> adj[32];
    for(int i = 0;i < n;i++) {
        for(int k = 0;k <= 30;k++) {
            if(v[i] & (1 << k)) {
                adj[k].pb(i);
            }
        }
    }

    bool flag = false;
    for(int i = 0;i <= 30;i++) {
        reverse(all(adj[i]));
        if(sz(adj[i]) >= 4) {
            flag = true;
        }
    }

    vector<int> tmp = v;
    int p = x;
    for(int i = 0;i + 1 < n;i++) {
        if(x == 0) break;
        for(int k = 30;k >= 0;k--) {
            if(x == 0) break;
            if(v[i] & (1 << k)) {
                if(sz(adj[k]) > 1) {
                    v[adj[k].back()] ^= (1 << k);
                    adj[k].pop_back();

                    v[adj[k].back()] ^= (1 << k);
                    adj[k].pop_back();

                    x--;
                } else if(sz(adj[k]) == 1) {
                    v[adj[k].back()] ^= (1 << k);
                    adj[k].pop_back();

                    v.back() ^= (1 << k);
                    adj[k].pb(n - 1);
                    x--;
                }
            }
        }
    }

    if(x & 1) {
        if(!flag) {
            v[n - 1] ^= 1;
            v[n - 2] ^= 1;
        }
    }


    for(int i = 0;i + 1 < n;i++) {
        if(p == 0) break;
        for(int k = 30;k >= 0;k--) {
            if(p == 0) break;
            if(tmp[i] & (1 << k)) {
                tmp[i] ^= (1 << k);
                tmp.back() ^= (1 << k);
                p--;
            }
        }
    }

    if(p & 1) {
        if(!flag) {
            tmp[n - 1] ^= 1;
            tmp[n - 2] ^= 1;
        }
    }

    vector<int> ans = v;
    for(int i = 0;i < n;i++) {
        if(v[i] == tmp[i]) {
            continue;
        } else if(v[i] < tmp[i]) {
            break;
        } else {
            ans = tmp;
            break;
        }
    }

    vpnt(ans);
}

int main() {
    go();
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
