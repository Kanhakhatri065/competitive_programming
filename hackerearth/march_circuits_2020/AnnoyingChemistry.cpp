#include <bits/stdc++.h>

using namespace std;

long long int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }

    return gcd(b % a, a);
}

long long int lcm(int a, int b) {
    return (a * b) / gcd(a,b);
}


int main() {
    long long int x, y, p, q;
    cin >> x >> y >> p >> q;

    long long int b1, b2, b3;

    /*long long int lcm_carbon_atoms = lcm(x, p);
    
    b1 = lcm_carbon_atoms / x;

    b3 = lcm_carbon_atoms / p;

    long long int lcm_hydrogen_atoms = lcm(y, (b3 *  q));

    b2 = lcm_hydrogen_atoms / y;

    b3 *= (lcm_hydrogen_atoms / q);

    b1 = (b3 * p) / x;

    b2 = (b3 * q) / y;
    */

   b3 = lcm(x, y);
   b1 = (p * b3) / x;
   b2 = (q * b3) / y;

    long long int gcd_b1_b2_b3 = gcd(b1, gcd(b2, b3));

    b1 /= gcd_b1_b2_b3;
    b2 /= gcd_b1_b2_b3;
    b3 /= gcd_b1_b2_b3;

    cout << b1 << " " << b2 << " " << b3 << endl;

    return 0;
}