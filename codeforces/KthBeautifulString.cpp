#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    int size;
    long long int position;
    for(int i = 0;i < testcases;i++) {
        cin >> size >> position;

        string str = "";
        for(int j = 0;j < size;j++) {
            str += 'a';
        }

        long long int count = 0;
        int flag = 0;
        for(int j = str.length() - 2;j >= 0;j--) {
            str[j] = 'b';
            for(int k = str.length() - 1;k > j;k--) {
                str[k] = 'b';
                count++;
                if(count == position) {
                    flag = 1;
                    break;
                }
                str[k] = 'a';
            }

            if(flag == 1) {
                break;
            }

            str[j] = 'a';
        }

        cout << str << endl;
    }
    return 0;
}