#include <iostream>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    for(int i = 0;i < testcases;i++){
        string inputStr;
        cin >> inputStr;

        int total = 0;
        for(int j = 1;j <= inputStr.length();j++){
            total += j;
        }

        cout << total << endl;
    }
    return 0;
}