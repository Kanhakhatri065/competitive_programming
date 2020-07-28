#include <iostream>

using namespace std;

int main(){
    int size;
    cin >> size;

    int actual_size = (2 * size) + 1;
    int arr[actual_size];
    for(int i = 0;i < actual_size;i++){
        cin >> arr[i];
    }
    int counter = 0;
    int number = 0;
    for(int i = 0;i < actual_size;i++){
        number = arr[i];
        counter = 1;
        for(int j = 0;j < actual_size;j++){
            if(j == i){
                continue;
            }

            if(arr[j] == arr[i]){
                counter++;
            }
        }

        if(counter % 2 != 0){
            break;
        }
    }

    cout << number << endl;

    return 0;
}