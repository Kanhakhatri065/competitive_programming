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
const int MOD = 1e9 + 7;
const int N = 1e4 + 5;
int par[N], rnk[N], dist[N];
void make_set(int v) {
    par[v] = v;
    rnk[v] = 0;
    dist[v] = 0;
}

int find_set(int v) {
    if(par[v] != v) {
        int x = par[v];
        par[v] = find_set(x);
        dist[v] ^= dist[x];
    }

    return par[v];
}

void union_sets(int u, int v, int d) {
    int pu = find_set(u), pv = find_set(v);
    if(rnk[pu] < rnk[pv]) {
        par[pu] = pv;
        dist[pu] = d ^ dist[u] ^ dist[v];
    } else {
        par[pv] = pu;
        dist[pv] = d ^ dist[u] ^ dist[v];
        if(rnk[u] == rnk[v]) rnk[u]++;
    }
}

int main() {
    while(true) {
        int n;cin >> n;
        if(n == -1) break;
        int q;cin >> q;
        int ans = 0, count = 0;
        bool valid = true;
        map<int, int> mp;
        
        while(q--) {
            int u, v;cin >> u >> v;
            string s;cin >> s;

            if(valid) {
                if(u <= 0 || u > n || v <= 0 || v > n || u > v) valid = false;
                else {
                    u--;
                    if(mp.find(u) == mp.end()) {
                        make_set(count);
                        mp[u] = count++;
                    }

                    if(mp.find(v) == mp.end()) {
                        make_set(count);
                        mp[v] = count++;
                    }

                    u = mp[u], v = mp[v];

                    int pu = find_set(u), pv = find_set(v), d = (s[0] == 'e') ? 0 : 1;
                    
                    if(pu == pv && (dist[u] ^ dist[v] ^ d) == 1) valid = false;
                    else if(pu != pv) union_sets(u, v, d);
                    if(valid) ans++;
                }
            }
        }

        pf(ans);
    }
}
