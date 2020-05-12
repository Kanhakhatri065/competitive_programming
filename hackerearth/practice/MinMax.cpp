#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int size;
    cin >> size;

    int arr[size];
    for(int i = 0;i < size;i++){
        cin >> arr[i];
    }

    sort(arr, arr + size);

    int min_number = arr[0];
    int max_number = arr[size - 1];

    int flag = 0;
    for(int i = 0;i < size;i++){
        if(arr[i] >= min_number && arr[size - 1] <= max_number){
            continue;
        } else {
            flag = 1;
            break;
        }
    }    

    if(flag == 1){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    
    return 0;
}