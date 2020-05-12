#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int size;
    cin >> size;

    long long int arr[size];
    for(int i = 0;i < size;i++) {
        cin >> arr[i];
    }

    sort(arr, arr + size);

    int queries;
    cin >> queries;

    long long int x;
    for(int i = 0;i < queries;i++) {
        cin >> x;

        int l = 0;
        int r = size - 1;

        int mid = l + (r - l) / 2;

        while(arr[mid] != x) {
            if(arr[mid] < x) {
                l = mid + 1;
            } else if(arr[mid] == x) {
                break;
            } else {
                r = mid - 1;
            }
            mid = l + (r - l) / 2;
        }

        cout << (mid + 1) << endl;
    }

    return 0;
}