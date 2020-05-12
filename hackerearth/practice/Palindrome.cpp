#include <iostream>

using namespace std;

int main(){
    long long int testcases;
    cin >> testcases;

    for(long long int i = 0;i < testcases;i++){
        string input;
        cin >> input;

        int flag = 0;
        for(long long int j = 0;j < input.size();j++){
            if(input[j] != input[input.size() - 1 -j]){
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