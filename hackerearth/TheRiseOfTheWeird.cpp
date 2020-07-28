#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    cin >> size;

    int arr[size];
    for(int i = 0;i < size;i++) {
        cin >> arr[i];
    }

    vector<int> even;
    vector<int> odd;

    long int evenSum = 0;
    long int oddSum = 0;

    for(int i = 0;i < size;i++) {
        if(arr[i] % 2 == 0) {
            even.push_back(arr[i]);
            evenSum += arr[i];
        } else {
            odd.push_back(arr[i]);
            oddSum += arr[i];
        }
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    for(int i = 0;i < even.size();i++) {
        cout << even[i] << " ";
    }

    cout << evenSum << " ";

    for(int i = 0;i < odd.size();i++) {
        cout << odd[i] << " ";
    }

    cout << oddSum << endl;

    return 0;
}