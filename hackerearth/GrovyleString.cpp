#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;
    
    string input;
    for(int i = 0;i < testcases;i++) {
        cin >> input;

        sort(input.begin(), input.end());

        char outputArr[input.length()];

        int middle = input.length() / 2;
        int left = middle;
        int right = middle;

        int counter = input.length() - 1;
        outputArr[middle] = input[counter--];
        while(counter >= 0) {
            outputArr[++right] = input[counter--];
            outputArr[--left] = input[counter--];
        }

        for(int j = 0;j < input.length();j++) {
            cout << outputArr[j];
        }

        cout << endl;
    }

    return 0;
}