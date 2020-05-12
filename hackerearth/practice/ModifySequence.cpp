#include <iostream>

using namespace std;

int main(){
    int size;
    cin >> size;

    int arr[size];
    for(int i = 0;i < size;i++){
        cin >> arr[i];
    }

    int flag = 0;
    for(int i = 0;i < size - 1;i++){
        if(arr[i] <= arr[i + 1]){
            arr[i + 1] -= arr[i];
            arr[i] = 0;
        }
    }

    for(int i = 0;i < size;i++){
        if(arr[i] != 0){
            flag = 1;break;
        }
    }

    if(flag == 0){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}