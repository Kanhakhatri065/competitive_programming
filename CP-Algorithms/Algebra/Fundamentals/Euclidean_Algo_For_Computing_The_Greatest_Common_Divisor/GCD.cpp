#include <bits/stdc++.h>
using namespace std;

int recgcd1(int a, int b) {
    if(b == 0) return a;
    return recgcd1(b, a % b);
}

int recgcd2(int a, int b) {
    return b ? recgcd2(b, a % b) : a;
}

int itergcd(int a, int b) {
    while(b) {
        a %= b;
        swap(a, b);
    }

    return a;
}

int main() {
    int a = 20, b = 50;
    cout << "Rec gcd 1 : " << recgcd1(a, b) << endl;
    cout << "Rec gcd 2 : " << recgcd2(a, b) << endl;
    cout << "Iter gcd : " << itergcd(a, b) << endl;
    return 0;
}
