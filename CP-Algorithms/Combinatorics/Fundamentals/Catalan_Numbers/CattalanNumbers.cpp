#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 1e3 + 5;
int catalan[MAX];
void init() {
    catalan[0] = catalan[1] = 1;
    for(int i = 2;i < MAX;i++) {
        catalan[i] = 0;
        for(int j = 0;j < i;j++) {
            catalan[i] += (catalan[j] * catalan[i - j - 1]) % MOD;
            if(catalan[i] >= MOD) {
                catalan[i] -= MOD;
            }
        }
    }
}

int main() {
    init();

    for(int i = 1;i <= 10;i++) {
        cout << "i : " << i << " val : " << catalan[i] << endl;
    } 

    return 0;
}
