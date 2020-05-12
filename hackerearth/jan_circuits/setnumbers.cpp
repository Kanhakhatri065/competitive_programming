#include <iostream>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    for(int i = 0;i < testcases;i++){
        int input_number;
        cin >> input_number;

        int binary_input = 0;
        int remainder = 0;
        int one = 0;
        int digits = 0;
        while(input_number != 0){
            remainder = input_number % 2;
            binary_input = binary_input * 10 + remainder;
            input_number = input_number / 2;
            
            if(remainder == 1){
                one++;
            }

            digits++;
        }
        int output_digits = 0;
        if(one == digits){
            output_digits = digits;
        } else {
            output_digits = digits - 1;
        }

        int output_number = 0;
        int base = 1;
        while(output_digits != 0){
            int last_digit = 1;
            output_number += last_digit * base;
            base = base * 2;
            output_digits--;
        }

        cout << output_number << endl;
        
    }

    return 0;
}