#include <iostream>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    int number = 0;
    for(int i = 0;i < testcases;i++){
        cin >> number;

        int count = 0;
        while(number != 0){
            count += number % 2;
            number /= 2;
        }
        cout << count << endl;
    }
    return 0;
}