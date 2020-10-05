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

    int r_a, s_a, p_a;
    cin >> r_a >> s_a >> p_a;

    int r_b, s_b, p_b;
    cin >> r_b >> s_b >> p_b;

    int mx = min(r_a, s_b) + min(s_a, p_b) + min(p_a, r_b);
    int mn1, mn2, mn3;

    if(true) {
        int t_r_a = r_a, t_s_a = s_a, t_p_a = p_a;
        int t_r_b = r_b, t_s_b = s_b, t_p_b = p_b;

        if(t_r_a <= t_p_b) {
            t_p_b -= t_r_a;
            t_r_a = 0;
        } else {
            t_r_a -= t_p_b;
            t_p_b = 0;
        }

        if(t_r_a <= t_r_b) {
            t_r_b -= t_r_a;
            t_r_a = 0;
        } else {
            t_r_a -= t_r_b;
            t_r_b = 0;
        }

        if(t_s_a <= t_r_b) {
            t_r_b -= t_s_a;
            t_s_a = 0;
        } else {
            t_s_a -= t_r_b;
            t_r_b = 0;
        }

        if(t_s_a <= t_s_b) {
            t_s_b -= t_s_a;
            t_s_a = 0;
        } else {
            t_s_a -= t_s_b;
            t_s_b = 0;
        }

        if(t_p_a <= t_s_b) {
            t_s_b -= t_p_a;
            t_p_a = 0;
        } else {
            t_p_a -= t_s_b;
            t_s_b = 0;
        }

        if(t_p_a <= t_p_b) {
            t_p_b -= t_p_a;
            t_p_a = 0;
        } else {
            t_p_a -= t_p_b;
            t_p_b = 0;
        }
    
        mn1 = t_r_a + t_s_a + t_p_a;
    }

    if(true) {
        int t_r_a = r_a, t_s_a = s_a, t_p_a = p_a;
        int t_r_b = r_b, t_s_b = s_b, t_p_b = p_b;

        if(t_s_a <= t_r_b) {
            t_r_b -= t_s_a;
            t_s_a = 0;
        } else {
            t_s_a -= t_r_b;
            t_r_b = 0;
        }

        if(t_s_a <= t_s_b) {
            t_s_b -= t_s_a;
            t_s_a = 0;
        } else {
            t_s_a -= t_s_b;
            t_s_b = 0;
        }

        if(t_r_a <= t_p_b) {
            t_p_b -= t_r_a;
            t_r_a = 0;
        } else {
            t_r_a -= t_p_b;
            t_p_b = 0;
        }

        if(t_r_a <= t_r_b) {
            t_r_b -= t_r_a;
            t_r_a = 0;
        } else {
            t_r_a -= t_r_b;
            t_r_b = 0;
        }

        if(t_p_a <= t_s_b) {
            t_s_b -= t_p_a;
            t_p_a = 0;
        } else {
            t_p_a -= t_s_b;
            t_s_b = 0;
        }

        if(t_p_a <= t_p_b) {
            t_p_b -= t_p_a;
            t_p_a = 0;
        } else {
            t_p_a -= t_p_b;
            t_p_b = 0;
        }
    
        mn2 = t_r_a + t_s_a + t_p_a;
    }

    if(true) {
        int t_r_a = r_a, t_s_a = s_a, t_p_a = p_a;
        int t_r_b = r_b, t_s_b = s_b, t_p_b = p_b;

        if(t_p_a <= t_s_b) {
            t_s_b -= t_p_a;
            t_p_a = 0;
        } else {
            t_p_a -= t_s_b;
            t_s_b = 0;
        }

        if(t_p_a <= t_p_b) {
            t_p_b -= t_p_a;
            t_p_a = 0;
        } else {
            t_p_a -= t_p_b;
            t_p_b = 0;
        }

        if(t_r_a <= t_p_b) {
            t_p_b -= t_r_a;
            t_r_a = 0;
        } else {
            t_r_a -= t_p_b;
            t_p_b = 0;
        }

        if(t_r_a <= t_r_b) {
            t_r_b -= t_r_a;
            t_r_a = 0;
        } else {
            t_r_a -= t_r_b;
            t_r_b = 0;
        }

        if(t_s_a <= t_r_b) {
            t_r_b -= t_s_a;
            t_s_a = 0;
        } else {
            t_s_a -= t_r_b;
            t_r_b = 0;
        }

        if(t_s_a <= t_s_b) {
            t_s_b -= t_s_a;
            t_s_a = 0;
        } else {
            t_s_a -= t_s_b;
            t_s_b = 0;
        }
    
        mn3 = t_r_a + t_s_a + t_p_a;
    }


    cout << min({mn1, mn2, mn3}) << " " << mx << endl;
}

int main() {
    go();
    solve();
    return 0;
}