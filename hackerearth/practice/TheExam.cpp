#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    long long int x, l, n;
    while(testcases--) {
        cin >> x >> l >> n;

        if(n == 0) {
            cout << "0" << endl;
        } else {
            unsigned long long int x_max = l / pow(2, n - 1);
            if(x < x_max) {
                cout << "0" << endl;
            } else {
                cout << (x - x_max) << endl;
            }
        }
    }

    return 0;
}