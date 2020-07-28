#include <iostream>

using namespace std;

int main(){
    string input;
    cin >> input;

    int consecutive_zeros = 0;
    int consecutive_ones = 0;

    int flag = 0;
    for(int i = 0;i < input.length();i++){
        if((i == 0) && (input[i] == '0')){
            consecutive_zeros = 1;
        } else if((i == 0) && (input[i] == '1')){
            consecutive_ones == 1;
        } else if(input[i] == '1' && input[i-1] == '1'){
            consecutive_ones++;
        } else if(input[i] == '0' && input[i-1] == '1'){
            consecutive_ones = 0;
            consecutive_zeros = 1;
        } else if(input[i] == '0' && input[i-1] == '0'){
            consecutive_zeros++;
        } else if(input[i] == '1' && input[i-1] == '0'){
            consecutive_zeros = 0;
            consecutive_ones = 1;
        }
        
        if(consecutive_ones == 6 || consecutive_zeros == 6){
            flag = 1;
            break;
        }
    }

    if(flag == 1){
        cout << "Sorry, sorry!" << endl;
    } else {
        cout << "Good luck!" << endl;
    }
    return 0;
}