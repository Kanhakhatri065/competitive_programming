#include <iostream>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    for(int i = 0;i < testcases;i++){
        int size;
        cin >> size;

        int arr[size];
        for(int j = 0;j < size;j++){
            cin >> arr[j];
        }

        int flag = 0;
        unsigned long long int total = 0;
        for(int j = 0;j < size;j++){
            total += arr[j];
        }

        for(int j = 0;j < size;j++){
            if((total - arr[j]) <= arr[j]){
                flag = 1;
            }
        }

        if(flag == 1){
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}