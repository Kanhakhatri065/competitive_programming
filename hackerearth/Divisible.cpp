#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    cin >> size;

    string str, store = "";
    for(int i = 0;i < size;i++) {
        cin >> str;

        if(i < (size / 2)) {
            store += str[0];
        } else {
            store += str[str.length() - 1];
        }
    }
    
    int number = 0;
    stringstream ss(store);
    ss >> number;


    if(number % 11 == 0) {
        cout << "OUI" << endl;
    } else {
        cout << "NON" << endl;
    }

    return 0;
}