#include <iostream>

using namespace std;

bool checkPalindrome(long long int number){
    string input = std::to_string(number);
    
    for(int i = 0;i < input.length();i++){
        if(input[i] != input[input.length() - i - 1]){
            return false;
        }
    }

    return true;
}

int main(){
    int testcases;
    cin >> testcases;

    long long int number, kth;
    for(int i = 0;i < testcases;i++){
        cin >> number >> kth;

        long long int output = number;
        long long int counter = 0;

        while(counter != kth){
            if(checkPalindrome(output)){
                counter++;
            }


            output++;
        }

        cout << (output - 1) << endl;
    }
    return 0;
}