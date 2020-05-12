#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    long long int number;
    while(testcases--) {
        cin >> number;

        long long int count = 0;
        for(long long int i = 5;(number / i) > 0;i *= 5) {
            count += (number / i);
        }

        cout << count << endl;
    }

    return 0;
}