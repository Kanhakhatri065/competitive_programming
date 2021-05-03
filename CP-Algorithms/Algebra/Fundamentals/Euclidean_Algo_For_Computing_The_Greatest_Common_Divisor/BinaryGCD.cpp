#include <bits/stdc++.h>
using namespace std;

int binary_gcd(int a, int b) {
    if(!a || !b) return a | b;
    
    int shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if(a > b) swap(a, b);
        b -= a;
    } while(b);

    return a << shift;
}

int main() {
    int a = 16 * 7, b = 4 * 7 * 7;
    cout << "GCD of " << a << " and " << b << " is : " << binary_gcd(a, b) << endl;
    return 0;
}
