#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long int size;
    cin >> size;

    long long int arr[size];
    for(long long int i = 0;i < size;i++) {
        cin >> arr[i];
    }

    sort(arr, arr + size);
    
    long long int count = 0;
    for(long long int i = 0;i < size - 1;i++) {
        if(arr[i] == arr[i - 1]) {
            count++;
        }
    }

    cout << count << endl;
    
    return 0;
}