#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long int arr[n];
    for(int i = 0;i < n;i++) {
        cin >> arr[i];
    }

    int identityArr[n];
    for(int i = 0;i < n;i++) {
        identityArr[i] = i + 1;
    }

    int queries;
    cin >> queries;

    for(int i = 0;i < queries;i++) {
        int ind, element;
        cin >> ind >> element;

        arr[ind - 1] = element;

        long long int arrIntermediate[n];
        for(int j = 0;j < n;j++) {
            arrIntermediate[j] = arr[j];
        }

        int countSumMin = 2 * n, countSum = 0, countShifts = -1, countChanges = 0, temp;
        for(int j = 0;j < n;j++) {
            countShifts++;
            countChanges = 0;
            for(int k = 0;k < n;k++) {
                if(arrIntermediate[k] != identityArr[k]) {
                    countChanges++;
                }
            }

            countSum = countShifts + countChanges;
            if(countSumMin > countSum) {
                countSumMin = countSum;
            }

            if(countSumMin == 1) {
                break;
            }

            long long int temp = arrIntermediate[0];

            for(int j = 1;j < n;j++) {
                arrIntermediate[j - 1] = arrIntermediate[j];
            }

            arrIntermediate[n - 1] = temp;
        } 
        cout << countSumMin << endl;
    }

    return 0;
}