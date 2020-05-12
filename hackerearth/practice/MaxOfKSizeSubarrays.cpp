#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int size, ksize;
    cin >> size >> ksize;

    long long int arr[size];
    for(int i = 0;i < size;i++){
        cin >> arr[i];
    }

    long long int max;
    for(int i = 0;i <= size - ksize;i++){
        max = arr[i];
        for(int j = 1;j < ksize;j++){
            if(arr[i + j] > max){
                max = arr[i + j];
            }
        }
        cout << max << " ";
    }
    cout << endl;
    return 0;
}