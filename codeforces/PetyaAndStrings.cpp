#include <bits/stdc++.h>

using namespace std;

int main() {
    string str1;
    cin >> str1;
    for_each(str1.begin(), str1.end(), [](char & c) {
        c = toupper(c);
    });

    string str2;
    cin >> str2;
    for_each(str2.begin(), str2.end(), [](char & c) {
        c = toupper(c);
    });

    if(str1 == str2) {
        cout << "0" << endl;
    } else if(str1 > str2) {
        cout << "1" << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}