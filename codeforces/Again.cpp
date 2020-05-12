#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;

    int number = (int)str[str.size() - 1] - 48;

    if(number % 2 == 0) {
        cout << "0" << endl;
    } else {
        cout << "1" << endl;
    }

    return 0;
}