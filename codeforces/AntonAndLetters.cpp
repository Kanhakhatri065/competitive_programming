#include <bits/stdc++.h>

using namespace std;

int main() {
    string input;
    getline(cin, input);

    string onlyLetters = "";
    for(int i = 0;i < input.size();i++) {
        if(input[i] >= 97 && input[i] <= 122) {
            onlyLetters += input[i];
        }
    }

    unordered_map<char, int> m;

    for(int i = 0;i < onlyLetters.length();i++) {
        m[onlyLetters[i]]++;
    }

    int count = m.size();
    
    cout << count << endl;

    return 0;
}