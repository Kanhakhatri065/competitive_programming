#include <iostream>

using namespace std;

int main() {
    string input;
    cin >> input;

    int firstLetter = input[0];

    if(firstLetter >= 97 && firstLetter <= 122) {
        input[0] = (firstLetter - 97) + 65;
    }

    cout << input << endl;

    return 0;
}