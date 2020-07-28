#include <iostream>

using namespace std;

int main() {
    long long int a, b;
    cin >> a >> b;

    long long int count = 0;
    while(a <= b) {
        count++;
        a *= 3;
        b *= 2;
    }

    cout << count << endl;
    return 0;
}