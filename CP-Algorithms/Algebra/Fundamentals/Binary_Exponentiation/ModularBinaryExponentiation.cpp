#include <bits/stdc++.h>
using namespace std;

int64_t binpow(int64_t a, int64_t b, int64_t m) {
    int64_t res = 1;
    while(b) {
        if(b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }

    return res;
}

int main() {
    int64_t a = 5, b = 5, m = 100;
    cout << "a : " << 5 << " b : " << 5 << " m : " << m << endl;
    cout << "Binary exponentiation : " << binpow(a, b, m) << endl;
    return 0;
}
