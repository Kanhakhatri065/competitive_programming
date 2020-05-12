#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int size, k;
    cin >> size >> k;

    int arr[size];
    for(int i = 0;i < size;i++) {
        cin >> arr[i];
    }

    int score = arr[k - 1];

    sort(arr, arr + size);

    int count = 0;    
    for(int i = 0;i < size;i++) {
        if(arr[i] >= score && arr[i] > 0) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}