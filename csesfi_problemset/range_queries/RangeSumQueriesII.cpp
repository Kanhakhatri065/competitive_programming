/*** I came, I saw, I conquered. ***/
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;typedef unsigned long long ull;
/*** Input Output ***/
#define sc(a) cin >> a
#define pf(a) cout << a << endl
/*** Loops ***/
#define f(i, p, num) for(ll i = p; i < num; i++)
#define forIn(arr, num) for(ll i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
/*** Define Values ***/
#define mod1 1000000007
#define mod2 998244353
#define eps 1e-7
/*** Abbrevations **/
#define pb push_back
#define ff first
#define ss second
#define mem(name, value) memset(name, value, sizeof(name))
/*** STLs ***/
typedef vector<ll>vll;typedef set<ll>sll;typedef multiset<ll>msll;
typedef map<ll,ll>mll;typedef pair<ll,ll>pll;
/*** Sorts ***/
#define all(v) (v).begin(), (v).end()
#define srt(v) sort(all(v))
/*** Bit-Stuff ***/
#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
/*** Some Prints ***/
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
/*----------------------------------------------------------------*/
struct BIT {
    int N;
    vll bit;

    BIT(int n) {
        this->N = n;
        bit.assign(n + 1, 0);
    }

    void updateBIT(int n, int idx, int val) {
        idx += 1;

        while(idx <= n) {
            bit[idx] += val;
            idx += (idx & (-idx));
        }
    }

    BIT(vll a) : BIT(int(a.size())) {
        for(int i = 0;i < (int)a.size();i++) {
            updateBIT(N, i, a[i]);
        }
    }

    ll getSum(int idx) {
        ll sum = 0LL;

        idx += 1;
        while(idx > 0) {
            sum += bit[idx];
            idx -= (idx & (-idx));
        }

        return sum;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vll v(n);
    forIn(v, n);

    BIT b(v);

    int type, l, r;
    int dif;
    ll ans;
    while(q--) {
        cin >> type >> l >> r;
        if(type == 1) {
            dif = r - v[l - 1];
            v[l - 1] += dif;
            b.updateBIT(n, l - 1, dif);
        } else {
            l--;
            r--;

            if(l == 0) {
                ans = b.getSum(r);
            } else {
                ans = b.getSum(r) - b.getSum(l - 1);
            }

            pf(ans);
        }
    }
}

int main() {
    FAST_IO
    solve();
    return 0;
}