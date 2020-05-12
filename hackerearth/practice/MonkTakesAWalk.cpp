#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    string str;
    int count;
    for(int i = 0;i < testcases;i++) {
        cin >> str;

        count = 0;
        for(int j = 0;j < str.length();j++) {
            if(str[j] == 'a' || str[j] == 'A' || str[j] == 'e' || str[j] == 'E' || str[j] == 'i' || str[j] == 'I' || str[j] == 'o' || str[j] == 'O'
                || str[j] == 'u' || str[j] == 'U' ) {
                    count++;
                }
        }

        cout << count << endl;
    }

    return 0;
}