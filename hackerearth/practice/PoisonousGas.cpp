#include <iostream>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    for(int i = 0;i < testcases;i++){
        int size;
        cin >> size;

        unsigned long long int total_strength = 0;
        long long int per_strength = 0;
        for(int j = 0;j < size;j++){
            cin >>  per_strength;
            if(per_strength > 0){
                total_strength += per_strength;
            }
        }

        int flag = 0;
        while(total_strength != 0){
            if(total_strength == 1){
                flag = 1;
                break;
            }

            if(total_strength % 2 != 0){
                break;
            } else {
                total_strength /= 2;
            }
        }

        if(flag == 1){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}