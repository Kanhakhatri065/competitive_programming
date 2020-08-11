#include <iostream>

using namespace std;

const int MAX = 500;
int res[MAX];
int res_size;
int multiply(int x) {
    int carry = 0;
    
    for(int i =0;i < res_size;i++) {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry = prod / 10;
    }

    while(carry) {
        res[res_size] = carry % 10;
        carry /= 10;
        res_size++;
    }

    return res_size;
}

void factorial(int n) {
    res[0] = 1;
    res_size = 1;
    for(int x = 2;x <= n;x++) {
        res_size = multiply(x);
    }

    for(int i = res_size - 1;i >= 0;i--) {
        cout << res[i];
    }
    cout << endl;
}

int n;
void solve() {
    cin >> n;
    factorial(n);
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}