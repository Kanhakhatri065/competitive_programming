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

    int output = arr[0] + arr[size - 1];
    cout << output << endl;
    return 0;
}