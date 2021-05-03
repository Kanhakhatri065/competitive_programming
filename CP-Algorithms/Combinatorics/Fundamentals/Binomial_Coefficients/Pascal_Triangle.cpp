#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int C[N][N];
void precomputation() {
    C[0][0] = 1;
    for(int n = 1;n < N;n++) {
        C[n][0] = C[n][n] = 1;
        for(int k = 1;k < n;k++) {
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
        }
    }
}

int main() {
    precomputation();

    int n = 5, k = 2;
    cout << "n : " << n << " k : " << k << endl;
    cout << "Choosing k from n : " << C[n][k] << endl;

    return 0; 
}
