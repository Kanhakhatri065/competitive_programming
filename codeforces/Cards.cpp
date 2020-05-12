#include <iostream>

using namespace std;

int main() {
    int size;
    cin >> size;

    string str;
    cin >> str;

    int ones = 0;
    int zeros = 0;
    for(int i = 0;i < size;i++) {
        if(str[i] == 'n') {
            ones++;
        }

        if(str[i] == 'z') {
            zeros++;
        }
    }

    while(ones--) {
        cout << "1 ";
    }

    while(zeros--) {
        cout << "0 ";
    }

    cout << endl;

    return 0;
}