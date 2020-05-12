#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    string str;
    while(testcases--) {
        cin >> str;
        int flag = 0;
        for(int i = str.size() - 1;i >= 0;i--) {
            if(str[i] != '0') {
                flag = 1;
            }

            if(flag == 1) {
                cout << str[i];
            }
        }
        cout << endl;
    }
    return 0;
}