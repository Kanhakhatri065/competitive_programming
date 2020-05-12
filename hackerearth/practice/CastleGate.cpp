#include <iostream>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    for(int i = 0;i < testcases;i++){
        int number;
        cin >> number;

        int total = 0;
        for(int j = 1;j < number;j++){
            for(int k = j+1;k <=number;k++){
                if((j ^ k) <= number){
                    total++;
                }
            }
        }

        cout << total << endl;
    }

    return 0;
}