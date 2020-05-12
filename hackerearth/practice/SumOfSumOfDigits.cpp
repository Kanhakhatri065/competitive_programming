#include <bits/stdc++.h>

using namespace std;

long long int digitValue(long long int number) {
    if(number / 10 == 0) {
        return number;
    }

    long long int sum = 0;
    while(number != 0) {
        sum += (number % 10);
        number /= 10;
    }

    return digitValue(sum);
}


int main() {
    int size, queries;
    cin >> size >> queries;

    long long int arr[size];
    long long int temp;
    for(int i = 0;i < size;i++) {
        cin >> temp;
        arr[i] = digitValue(temp);
    }

    sort(arr, arr + size);

    int query[queries][2];
    for(int i = 0;i < queries;i++) {
        cin >> query[i][0] >> query[i][1];
    }

    long long int sum = 0;
    for(int i = 0;i < queries;i++) {
        sum = 0;
        if(query[i][0] == 1) {
            for(int j = size - 1;j >= size - query[i][1];j--) {
                sum += arr[j];
            }
        } else if(query[i][0] == 2) {
            for(int j = 0;j < query[i][1];j++) {
                sum += arr[j];
            }
        }

        cout << sum << endl;
    }

    return 0;
}