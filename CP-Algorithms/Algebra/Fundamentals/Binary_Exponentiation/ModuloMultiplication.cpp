#include <bits/stdc++.h>
using namespace std;

long long modmul(long long a, long long b, long long mod) {
    long long res = 0;
    a %= mod;
    while(b) {
        if(b & 1) res = (res + a) % mod;
        a = (2 * a) % mod;
        b >>= 1;
    }

    return res;
}

int main() {
    int a = 5, b = 3, m = 10;
    cout << "a : " << a << " b : " << b << " m : " << m << endl;
    cout << "(a * b) % m : " << modmul(a, b, m) << endl;
    return 0;
}
