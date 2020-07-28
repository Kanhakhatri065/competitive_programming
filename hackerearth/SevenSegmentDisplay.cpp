#include <iostream>

using namespace std;

int main(){
    int display[] = {6,2,5,5,4,5,6,3,7,6};

    int testcases;
    cin >> testcases;

    int total_matchsticks;
    for(int i = 0;i < testcases;i++){
        total_matchsticks = 0;
        int number;
        cin >> number;

        int remainder = 0;

        if(number == 0){
            total_matchsticks = 6;
        } else {
            while(number != 0){
                remainder = number % 10;
                total_matchsticks = total_matchsticks + display[remainder];
                number = number / 10;
            }
        }
        cout << total_matchsticks << endl;
        string output = "";
        if(total_matchsticks % 2 == 0){
            while(total_matchsticks != 0){
                total_matchsticks -= 2;
                output = output + "1";
            }
        } else {
            total_matchsticks -= 3;
            output =  output + "7";
            while(total_matchsticks != 0){
                total_matchsticks -= 2;
                output = output + "1";
            }
        }
        cout << output << endl;
    }

    return 0;
}