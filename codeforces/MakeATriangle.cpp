#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[3];
    for(int i = 0;i < 3;i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + 3);
    int count = 0;
    if(arr[0] + arr[1] > arr[2]) {
        cout << count << endl;
    } else {
        count = arr[2] - (arr[0] + arr[1]) + 1;
        cout << count << endl;
    }

    return 0;
}