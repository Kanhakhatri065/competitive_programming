#include <iostream>

using namespace std;

int main(){
    long long int numbers;
    cin >> numbers;

    unsigned long long int number = 0;
    long long int total = 0;
    for(int i = 0;i < numbers;i++){
        cin >> number;

        int flag = 0;
        while(number != 0){
            if(number == 1){
                flag = 1;
                break;
            }

            if(number % 2 != 0){
                break;
            } else {
                number /= 2;
            }
        }

        if(flag == 1){
            total++;
        }
    }

    cout << total << endl;

    return 0;
}