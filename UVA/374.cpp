#include <iostream>
using namespace std;

int a, b, n;
int binpow() {
    int res = 1;
    while(b) {
        if(b & 1) res = (1LL * res * a) % n;
        a = (1LL * a * a) % n;
        b >>= 1;
    }

    return res;
}

int main() {
    while(cin >> a >> b >> n) {
        cout << binpow() << endl;
    }
    return 0;
}
