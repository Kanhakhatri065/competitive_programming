#include <iostream>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    int size = 0;
    for(int i = 0;i < testcases;i++){
        cin >> size;

        long long int arr1[size];
        for(int j = 0;j < size;j++){
            cin >> arr1[j];
        }

        long long int arr2[size];
        for(int j = 0;j < size;j++){
            cin >> arr2[j];
        }

        int flag = 0;
        int counter = 0;
        for(int j = 0;j < size;j++){
            for(int k = 0;k < size;k++){
                if(arr1[j] == arr2[k]){
                    arr2[k] = -1;
                    break;
                }

                if(arr1[j] != arr2[k]){
                    counter++;
                }

                if(counter == size){
                    flag = 1;
                    break;
                }
            }

            if(flag == 1){
                break;
            }
        }

        if(flag == 0){
            for(int j = 0;j < size;j++){
                if(arr2[j] != -1){
                    flag = 1;
                    break;
                }
            }
        }

        if(flag == 1){
            cout << "-1" << endl;
        } else {
            for(int j = 0;j < size;j++){
                cout << arr1[j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}