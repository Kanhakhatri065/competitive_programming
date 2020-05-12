#include <iostream>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    string str;
    while(testcases--) {
        cin >> str;

        if(str[str.size() - 1] == 'o') {
            cout << "FILIPINO" << endl;
        } else if(str[str.size() - 1] == 'u') {
            cout << "JAPANESE" << endl;
        } else {
            cout << "KOREAN" << endl;
        }
    }
    return 0;
}