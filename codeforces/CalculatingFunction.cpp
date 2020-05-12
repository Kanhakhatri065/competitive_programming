#include <iostream>

using namespace std;

int main() {
    unsigned long long int number;
    cin >> number;

    long long int output = 0;

    long long int num_of_odd_numbers = 0;
    if(number % 2 == 0) {
        num_of_odd_numbers = number / 2;
    } else {
        num_of_odd_numbers = ((number) / 2) + 1;
    }

    
    output = (((number / 2) * ((number / 2) + 1))) - ((number / 2) * (number / 2));
    if(number % 2 != 0) {
        output -= number;   
    }

    cout << output << endl;

    return 0;
}