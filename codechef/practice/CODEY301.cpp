#include <iostream>

using namespace std;

long long int fun(long long int n) {
    return (n * (n + 1)) / 2 + 1;
}

int main() {
    long long int testcases;
    cin >> testcases;

    long long int number;
    while(testcases--) {
        cin >> number;

        cout << fun(number) << endl;
    }
    return 0;
}