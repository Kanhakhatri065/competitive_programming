#include <iostream>

using namespace std;

int main() {
    string str1;
    cin >> str1;

    string str2;
    cin >> str2;

    string output = "";

    int count = 0;
    for(int i = 0;i < str1.size();i++) {
        if(str1[i] == str2[i]) {
            output += str1[i];
        } else {
            count++;
            if(count % 2 ==1) {
                output += str1[i];
            } else {
                output += str2[i];
            }
        }
    }

    if(count % 2 == 1) {
        cout << "impossible" << endl;
    } else {
        cout << output << endl;
    }

    
    return 0;
}