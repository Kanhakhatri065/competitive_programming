#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void multiply(vector<vector<ll>> &f, vector<vector<ll>> &m, ll MOD) {
    ll x = ((f[0][0] * m[0][0]) % MOD + (f[0][1] * m[1][0]) % MOD) % MOD;
    ll y = ((f[0][0] * m[0][1]) % MOD + (f[0][1] * m[1][1]) % MOD) % MOD;
    ll z = ((f[1][0] * m[0][0]) % MOD + (f[1][1] * m[1][0]) % MOD) % MOD;
    ll w = ((f[1][0] * m[0][1]) % MOD + (f[1][1] * m[1][1]) % MOD) % MOD;

    f[0][0] = x;
    f[0][1] = y;
    f[1][0] = z;
    f[1][1] = w;
}

void power(vector<vector<ll>> &f, ll n, ll MOD) {
    if(n == 0 || n == 1) return;

    vector<vector<ll>> m({{1, 1}, {1, 0}});
    power(f, n / 2, MOD);
    multiply(f, f, MOD);
    if(n & 1) multiply(f, m, MOD);
}

ll fibonnaci(ll n, ll MOD) {
    vector<vector<ll>> f({{1, 1}, {1, 0}});
    if(n == 0) return 0;
    power(f, n - 1, MOD);
    return f[0][0];
}

int main() {
    ll MOD = 1e9 + 7;
        
    for(ll i = 0;i <= 5;i++) {
        cout << i << " fibonnaci element is : " << fibonnaci(i, MOD) << endl;
    }

    return 0;
}
