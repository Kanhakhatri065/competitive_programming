#include <iostream>

using namespace std;

int main(){
    int size,rotation;
    cin >> size >> rotation;

    int arr[size];
    for(int i = 0;i < size;i++){
        cin >> arr[i];
    }

    int temp;
    for(int i = 0;i < rotation;i++){
        temp = arr[0];
        for(int j = 0;j < size-1;j++){
            arr[j] = arr[j+1];
        }
        arr[size - 1] = temp;
    }

    for(int i = 0;i <size;i++){
        cout << arr[i] << " ";
    }
    return 0;
}