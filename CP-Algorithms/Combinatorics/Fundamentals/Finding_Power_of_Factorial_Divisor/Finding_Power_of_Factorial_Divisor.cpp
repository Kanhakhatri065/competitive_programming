#include <bits/stdc++.h>

using namespace std;

int fact_pow(int n, int k) {
    int res = 0;
    while(n) {
        n /= k;
        res += n;
    }

    return res;
}

int main() {
    int n = 10, k = 5;
    cout << "n : " << n << " k : " << k << endl;

    cout << "largest power of k : " << fact_pow(n, k) << endl;
    
    return 0;
}
