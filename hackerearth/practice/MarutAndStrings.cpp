#include <iostream>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    if(testcases == 0) {
        cout << "Invalid Test" << endl;
    }

    string input;
    for(int i = 0;i < testcases;i++) {
        cin >> input;

        int flag = 0;
        if(testcases > 10 && flag == 0) {
            cout << "Invalid Test" << endl;
            flag = 1;
            continue;
        }

        if(input.empty()) {
            cout << "" << endl;
        }

        int lowerCaseCounter = 0;
        int upperCaseCounter = 0;
        for(int j = 0;j < input.size();j++) {
            if(input[j] >= 65 && input[j] <= 90) {
                upperCaseCounter++;
            } else if(input[j] >= 97 && input[j] <= 122) {
                lowerCaseCounter++;
            }
        }

        if((lowerCaseCounter == 0 && upperCaseCounter == 0) || (input.size() > 100)) {
            cout << "Invalid Input" << endl;
        } else {
            if(lowerCaseCounter > upperCaseCounter) {
                cout << upperCaseCounter << endl;
            } else if(lowerCaseCounter < upperCaseCounter) {
                cout << lowerCaseCounter << endl;
            } else {
                cout << upperCaseCounter << endl;
            }
        }
    }

    return 0;
} 