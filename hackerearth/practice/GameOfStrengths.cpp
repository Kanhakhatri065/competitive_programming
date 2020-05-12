#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    int size;
    for(int i = 0;i < testcases;i++) {
        cin >> size;

        long long int arr[size];
        long long int max_size = 0;
        for(int j = 0;j < size;j++) {
            cin >> arr[j];
            if(j == 0) {
                max_size = arr[j];
            }

            if(max_size <= arr[j]) {
                max_size = arr[j];
            }
        }

        long long int sum = 0;
        for(int j = 0;j < size -1;j++) {
            for(int k = j + 1;k < size;k++) {
                sum += abs(arr[j] - arr[k]);
            }
        }

        long long int overall_power = (sum * max_size)%(1000000007);

        cout << overall_power << endl;
    }

    return 0;
}