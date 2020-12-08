#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int total, atmost;
    cin >> total >> atmost;

    int arr[total];
    for(int i = 0;i < total;i++) {
        cin >> arr[i];
    }

    sort(arr, arr + total);

    int sum = 0;
    int tempSum = 0;
    for(int i = 0;i < total;i++) {
        if(atmost == 0) {
            break;
        }

        tempSum += arr[i];
        
        if(tempSum <= sum) {
            sum += arr[i];
            atmost--;
        }

        if(tempSum > sum) {
            break;
        }
    }

    int output = (-1 * sum);
    cout << output << endl;

    return 0;
}
