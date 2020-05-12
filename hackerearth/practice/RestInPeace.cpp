#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    long long int number;
    for(int i = 0;i < testcases;i++) {
        cin >> number;

        bool flag = true;

        if(number % 21 == 0) {
            flag = false;
        }

        if(flag == true) {
            string str = to_string(number);

            int pos = str.find("21");

            if(pos >= 0 && pos < str.length()) {
                flag = false;
            }
        }

        if(flag == true) {
            cout << "The streak lives still in our heart!" << endl;
        } else {
            cout << "The streak is broken!" << endl;
        }
    }

    return 0;
}