#include <iostream>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    string str;
    for(int i = 0;i < testcases;i++) {
        cin >> str;

        if(str.length() > 10) {
            string output = "";
            output += str[0];

            int count = str.length() - 2;
            output += to_string(count);
            output += str[str.length() - 1];
            
            cout << output << endl;
        } else {
            cout << str << endl;
        }
    }

    return 0;
}