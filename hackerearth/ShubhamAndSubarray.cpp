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
const int MAX = 1005;
ll arr[MAX], power1[MAX], power2[MAX], seen[MAX], base1 = 127, base2 = 129, mod1 = mod, mod2 = mod + 2;
set<pair<ll, ll>> s;
inline ll add(ll x, ll y, ll modulus) {
    x += y;
    if(x >= modulus) {
        x -= modulus;
    }

    return x;
}

inline ll mul(ll x, ll y, ll modulus) {
    return (x * y) % modulus;
}

void solve() {
    power1[0] = 1;
    power2[0] = 1;

    for(int i = 1;i <= 1000;i++) {
        power1[i] = mul(power1[i - 1], base1, mod1);
        power2[i] = mul(power2[i - 1], base2, mod2);
    }

    int n;
    sc(n);

    for(int i = 1;i <= n;i++) {
        sc(arr[i]);
    }

    int hash_val1, hash_val2;
    for(int i = 1;i <= n;i++) {
        hash_val1 = 0, hash_val2 = 0;
        for(int j = i;j <= n;j++) {
            if(!seen[arr[j]]) {
                hash_val1 = add(hash_val1, power1[arr[j]], mod1);
                hash_val2 = add(hash_val2, power2[arr[j]], mod2);
            }

            seen[arr[j]] = 1;
            s.insert({hash_val1, hash_val2});
        }

        for(int j = 1;j <= n;j++) {
            seen[arr[j]] = 0;
        }
    }

    pf(int(s.size()));
}

int main() {
    go();
    solve();
    return 0;
}