#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    int len;
    string str;
    while(testcases--) {
        cin >> len >> str;
        if(len == 11) {
            if(str[0] == '8') {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else if(len < 11) {
            cout << "NO" << endl;
        } else {
            int store = -1;
            for(int i = 0;i < str.size();i++) {
                if(str[i] == '8') {
                    store = len - i;
                    break;
                }
            }

            if(store == -1) {
                cout << "NO" << endl;
            } else {
                if(store >= 11) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            }
        }
    }
    return 0;
}