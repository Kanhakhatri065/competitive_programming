#include <iostream>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    string str;
    while(testcases--) {
        cin >> str;

        if(str.size() % 2 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}