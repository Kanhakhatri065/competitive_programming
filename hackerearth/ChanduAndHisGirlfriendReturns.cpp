#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    int size1, size2;
    for(int i = 0;i < testcases;i++) {
        cin >> size1 >> size2;

        long long int arr[size1 + size2];
        long long int temp;
        for(int j = 0;j < size1;j++) {
            cin >> temp;
            arr[j] = temp;
        }

        long long int arr2[size2];
        for(int j = size1;j < size1 + size2;j++) {
            cin >> temp;
            arr[j] = temp;
        }

        sort(arr, arr + (size1 + size2));

        for(int j = size1 + size2 -1;j >= 0;j--) {
            cout << arr[j] << " ";
        }
        cout << endl;
    }

    return 0;
}