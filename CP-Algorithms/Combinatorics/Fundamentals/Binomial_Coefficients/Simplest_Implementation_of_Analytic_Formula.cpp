#include <bits/stdc++.h>

using namespace std;

int C(int n, int k) {
    int res = 1;
    for(int i = n - k + 1;i <= n;i++) res *= i;
    for(int i = 2;i <= k;i++) res /= i;

    return res;
}

int main() {
    int n = 5, k = 2;
    cout << "n : " << n << " k : " << k << endl;
    cout << "choosing k from n : " << C(n, k) << endl;

    return 0;
}
