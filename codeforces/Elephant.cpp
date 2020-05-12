#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int number;
    cin >> number;

    long long int count = 0;
    while(number != 0) {
        if(number >= 5) {
            count += (number / 5);
            number -= (5 * (number / 5));
        }

        if(number > 0) {
            number = 0;
            count++;
        }
    }

    cout << count << endl;

    return 0;
}