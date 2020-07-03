#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    string str1, str2;
    for(int i = 0;i < testcases;i++) {
        cin >> str1 >> str2;

        vector<int> store;

        stringstream ss1(str1);
        stringstream ss2(str2);

        int first, second;
        ss1 >> first;
        ss2 >> second;

        int sum = first + second;
        store.push_back(sum);

        char temp1, temp2;
        for(int j = 0;j < str1.length();j++) {
            for(int k = 0;k < str2.length();k++) {
                temp1 = str1[j];
                temp2 = str2[k];

                str1[j] = temp2;
                str2[k] = temp1;

                stringstream ss1(str1);
                stringstream ss2(str2);
                ss1 >> first;
                ss2 >> second;

                sum = first + second;

                store.push_back(sum);

                str1[j] = temp1;
                str2[k] = temp2;
            }
        } 

        sort(store.begin(), store.end());

        cout << store[store.size() - 1] << endl;
    }

    return 0;
}