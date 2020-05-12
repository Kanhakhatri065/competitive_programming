#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    long long int number, distinct;
    for(int i = 0;i < testcases;i++) {
        cin >> number >> distinct;

        if((number % 2 == 0) && (distinct % 2 != 0)) {
            cout << "NO" << endl;
        } else if((number % 2 != 0) && (distinct % 2 == 0)) {
            cout << "NO" << endl;
        } else {
            if((distinct * distinct) > number) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        }
    }

    return 0;
}