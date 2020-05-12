#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    string input;
    for(int i = 0;i < testcases;i++){
        cin >> input;

        int flag = 0;
        for(int j = 0;j < input.size() - 1;j++){
            if(abs(input[j] - input[j + 1]) % 24 != 1){
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