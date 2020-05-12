#include <bits/stdc++.h>

using  namespace std;

int main(){
    int testcases;
    cin >> testcases;

    for(int i = 0;i < testcases;i++){
        string input;
        cin >> input;


        long long int size = input.length();
        sort(input.begin(),input.end());

        
        int flag = 0;
        for(long long int j = 0;j < size - 1;j++){
            if((input[j + 1]) != (input[j] + 1)){
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}