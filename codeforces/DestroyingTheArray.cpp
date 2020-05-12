#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    cin >> size;

    long long int arr[size];
    for(int i = 0;i < size;i++) {
        cin >> arr[i];
    }

    int destroying_sequence[size];
    for(int i = 0;i < size;i++) {
        cin >> destroying_sequence[i];
    }

    vector<long long int> store_sum;
    long long int temp_sum;
    for(int i = 0;i < size;i++) {
        arr[destroying_sequence[i] - 1] = -1;
        
        temp_sum = 0;
        for(int j = 0;j < size;j++) {
            if(arr[j] != -1) {
                temp_sum += arr[j];
            }
            
            if(arr[j] == -1) {
                store_sum.push_back(temp_sum);
                temp_sum = 0;
            }

            if(j == size - 1) {
                store_sum.push_back(temp_sum);
            }
        }

        cout << *max_element(store_sum.begin(), store_sum.end()) << endl;
        store_sum.clear();
    }

    return 0;
}