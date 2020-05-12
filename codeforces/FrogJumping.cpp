#include <iostream>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    long long int a, b, k;
    while(testcases--) {
        cin >> a >> b >> k;

        cout << (((k - (k / 2)) * a) - ((k / 2) * b)) << endl;
    }

    return 0;
}