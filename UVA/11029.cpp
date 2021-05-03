#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k;
ll getLastDigits() {
    ll digits = 1;
    n %= 1000L;

    while(k) {
        if(k & 1) digits = (digits * n) % 1000LL;
        n = (n * n) % 1000LL;
        k >>= 1;
    }

    return digits;
}

int main() {
    int t;cin >> t;
    long double power;
    while(t--) {
        cin >> n >> k;
        power = (double)k * log10(n);
        int firstDigits = pow(10, power - floor(power)) * 100.0;
        cout << firstDigits << "..." << setw(3) << setfill('0') << getLastDigits() << "\n";
    }
    return 0;
}
