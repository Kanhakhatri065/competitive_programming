#include <iostream>
#include <math.h>

using namespace std;

int main(){
    unsigned long long int number;
    while(cin >> number){
        unsigned long long int count = 0;
        int flag = 0;
        if(number == 0){
            flag = 1;
        }
        while(number != 0){
            if(number % 2 != 0){
                break;
            }
            count++;
            number /= 2;
        }

        unsigned long long int output = (unsigned long long) pow(2, count);
        if(flag == 1){
            output = 0;
        }
        cout << output << endl;
    }
    return 0;
}