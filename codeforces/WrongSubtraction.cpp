#include <iostream>

using namespace std;

int main() {
    long long int number, k;
    cin >> number >> k;

    for(int i = 0;i < k;i++) {
        if(number % 10 != 0) {
            number--;
        } else {
            number /= 10;
        }
    }

    cout << number << endl;
    return 0;
}