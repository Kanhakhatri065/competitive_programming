#include <bits/stdc++.h>

using namespace std;

bool isVowel(char c) {
    if(c == 'a' || c == 'A' || c == 'o' || c == 'O' || c == 'y' || c == 'Y' || c == 'e' || c == 'E' || c == 'u' || c == 'U' || c == 'i' || c == 'I') {
        return true;
    }

    return false;
}

int main() {
    string str;
    cin >> str;

    string outputStr = "";
    for(int i = 0;i < str.size();i++) {
        if(!isVowel(str[i])) {
            if(str[i] >= 65 && str[i] <= 90) {
                int temp = str[i] - 65 + 97;
                outputStr = outputStr + "." + (char)temp;
            } else {
                outputStr = outputStr + "." + str[i];
            }
        }
    }

    cout << outputStr << endl;

    return 0;
}