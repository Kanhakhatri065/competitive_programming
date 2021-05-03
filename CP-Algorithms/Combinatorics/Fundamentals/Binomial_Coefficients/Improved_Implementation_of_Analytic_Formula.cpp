#include <bits/stdc++.h>

using namespace std;

int C(int n, int k) {
    double res = 1;
    for(int i = 1;i <= k;i++) {
        res = res * (n - k + i) / i;
    }

    return int(res + 0.01);
}

int main() {
    int n = 5, k = 2;
    cout << "n : " << n << " k : " << k << endl;
    cout << "Choosing k from n : " << C(n, k) << endl;
    return 0;
}
