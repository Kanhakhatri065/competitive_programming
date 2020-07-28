#include <iostream>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    unsigned long long int input = 0;
    unsigned long long int output = 0;
    for(int i = 0;i < testcases;i++){
        output = 0;
        cin >> input;

        for(unsigned long long int j = 2;j < input;j *= 2){
            for(unsigned long long int k = 1;k < j;k *= 2){
                if(j + k <= input){
                    output = (output + j + k) % 1000000007;
                }
            }
        }

        cout << output << endl;
    }
    return 0;
}