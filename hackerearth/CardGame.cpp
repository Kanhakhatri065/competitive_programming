#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int size1;
    cin >> size1;

    long long int arr1[size1];
    for(long long int i = 0;i < size1;i++) {
        cin >> arr1[i];
    }

    long long int size2;
    cin >> size2;

    long long int arr2[size2];
    for(long long int i = 0;i < size2;i++) {
        cin >> arr2[i];
    }


    long long int *maximum_arr2 = max_element(arr2 , arr2 + size2);

    long long int count = 0;
    for(long long int i = 0;i < size1;i++) {
        if(arr1[i] <= *maximum_arr2) {
            count += (*maximum_arr2 - arr1[i]) + 1;
        }
    }

    cout << count << endl;

    return 0;
}