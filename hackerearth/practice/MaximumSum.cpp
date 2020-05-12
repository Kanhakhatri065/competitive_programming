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

    int count = 1;
    long long int sum = arr[size - 1];

    for(int i = size - 2;i >= 0;i--) {
        if((sum + arr[i]) >= sum) {
            count++;
            sum += arr[i];
        } else {
            break;
        }
    }

    cout << sum << " " << count << endl;

    return 0;
}
