#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    int size, starting;
    for(int i = 0;i < testcases;i++) {
        cin >> size >> starting;

        int arr[size];
        for(int j = 0;j < size;j++) {
            cin >> arr[j];
        }

        int diff = size - starting;

        sort(arr, arr + size);
        
        int maxsum = 0;
        for(int j = size - 1;j >= starting;j--) {
            maxsum += arr[j];
        }

        int minsum = 0;
        for(int j = 0;j < size - starting;j++) {
            minsum += arr[j];
        }

        int output = maxsum - minsum;
        
        cout << output << endl;
    }

    return 0;
}