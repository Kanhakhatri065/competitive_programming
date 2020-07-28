#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int size;
    cin >> size;

    int arr[size];
    for(int i = 0;i < size;i++) {
        cin >> arr[i];
    }

    sort(arr, arr + size);

    int queries;
    cin >> queries;

    int power;
    for(int i = 0;i < queries;i++) {
        cin >> power;

        int count = 0;
        long long int power_count = 0;
        for(int j = 0;j < size;j++) {
            if(arr[j] <= power) {
                count++;
                power_count += arr[j];
            } else {
                break;
            }
        }

        cout << count << " " << power_count << endl;
    }

    return 0;
}