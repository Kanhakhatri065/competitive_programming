#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll recbinpow(ll a, ll b) {
    if(b == 0) return 1;
    ll res = recbinpow(a, b / 2);
    if(b & 1) return res * res * a;
    return res * res;
}

ll iterbinpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res *= a;
        a *= a;
        b >>= 1;
    }

    return res;
}

int main() {
    int a = 5, b = 5;
    cout << "a : " << a << " b : " << b << endl;
    cout << "Recursive binary exponentiation : " << recbinpow(a, b) << endl;
    cout << "Iterative binary exponentiation : " << iterbinpow(a, b) << endl;
    return 0;
}
