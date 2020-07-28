#include <bits/stdc++.h>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    for(int i = 0;i < testcases;i++){
        string input;
        cin >> input;

        vector<char> store;
        store.push_back('-');
        for(int j = 0;j < input.size();j++){
            char temp = input[j];

            int flag = 0;
            for(int k = 0;k < store.size();k++){
                if(temp == store[k]){
                    flag = 1;
                    break;
                }
            }

            if(flag == 0){
                store.push_back(temp);
            }
        }

        for(int j = 1;j < store.size();j++){
            cout << store[j];
        }
        cout << endl;
    }
    return 0;
}