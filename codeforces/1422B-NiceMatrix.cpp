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
    int n, m;
    cin >> n >> m;

    vector<vector<ll>> v(n, vector<ll>(m));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            sc(v[i][j]);
        }
    }

    ll corner_case = 0, corner_sum = 0;
    ll normal_case = 0, normal_sum = 0;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(i == 0 || i == n - 1) {
                if(j == 0 || j == m - 1) {
                    corner_case++;
                    corner_sum += v[i][j];
                } else {
                    normal_case++;
                    normal_sum += v[i][j];
                }
            } else {
                normal_case++;
                normal_sum += v[i][j];
            }
        }
    }

    ll corner1 = corner_sum / corner_case;
    ll corner2 = corner1;
    if(corner_sum % corner_case) {
        corner2++;
    }

    ll ans;
    if(normal_case == 0) {
        ll a1 = 0, a2 = 0;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                a1 += abs(v[i][j] - corner1);
            }
        }
        
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                a2 += abs(v[i][j] - corner2);
            }
        }

        ans = min({a1, a2});
    } else {
        ll normal1 = normal_sum / normal_case;
        ll normal2 = normal1;
        if(normal_sum % normal_case) {
            normal2++;
        }

        ll a1 = 0, a2 = 0, a3 = 0, a4 = 0;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(i == 0 || i == n - 1) {
                    if(j == 0 || j == m - 1) {
                        a1 += abs(v[i][j] - corner1);
                    } else {
                        a1 += abs(v[i][j] - normal1);
                    }
                } else {
                    a1 += abs(v[i][j] - normal1);
                }
            }
        }

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(i == 0 || i == n - 1) {
                    if(j == 0 || j == m - 1) {
                        a2 += abs(v[i][j] - corner1);
                    } else {
                        a2 += abs(v[i][j] - normal2);
                    }
                } else {
                    a2 += abs(v[i][j] - normal2);
                }
            }
        }

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(i == 0 || i == n - 1) {
                    if(j == 0 || j == m - 1) {
                        a3 += abs(v[i][j] - corner2);
                    } else {
                        a3 += abs(v[i][j] - normal1);
                    }
                } else {
                    a3 += abs(v[i][j] - normal1);
                }
            }
        }

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(i == 0 || i == n - 1) {
                    if(j == 0 || j == m - 1) {
                        a4 += abs(v[i][j] - corner2);
                    } else {
                        a4 += abs(v[i][j] - normal2);
                    }
                } else {
                    a4 += abs(v[i][j] - normal2);
                }
            }
        }

        ans = min({a1, a2, a3, a4});
    }

    pf(ans);
}

int main() {
    go();
    int t;
    sc(t);

    while(t--) {
        solve();
    }

    return 0;
}