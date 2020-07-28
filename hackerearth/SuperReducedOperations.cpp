#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;

    int flag = 0;
    while(flag == 0) {
        int temp = -1;
        for(int i = 0;i < str.size() - 1;i++) {
            if(str[i] == str[i + 1]) {
                temp = i;
                break;
            }

            if(i == str.size() - 2){
                flag = 1;
                break;
            }
        }

        if(flag == 1) {
            break;
        }

        str.erase(temp, 2);

        if(str.size() == 0) {
            break;
        }
    }

    if(str.size() != 0) {
        cout << str << endl;
    } else {
        cout << "Empty String" << endl;
    }

    return 0;
}