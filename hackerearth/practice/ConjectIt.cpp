#include <iostream>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    for(int i = 0;i < testcases;i++){
        int number;
        cin >> number;

        while(1){
            if(number == 1){
                break;
            }

            if(number % 2 == 0){
                number = number / 2;
            } else {
                number = (3 * number) + 1;
            }
        }

        cout << "YES" << endl;
    }

   return 0;
}