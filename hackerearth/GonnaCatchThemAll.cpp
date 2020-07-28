#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    cin >> size;

    long long int arr[size];
    for(int j = 0;j < size;j++) {
        cin >> arr[j];
    }

    sort(arr, arr + size, greater<long long int>());

    long long int num_of_days = 1;
    int i = 0;
    int j = 0;
    int flag = 0;
    
    


    while(arr[0] != 0) {
        if(i < size) {
            for(int j = 0;j < i;j++) {
                arr[j]--;
                if(j == i - 1) {
                    num_of_days++;
                }
            }
            
            i++;
        } else {
            if(flag == 0) {
                j = i - 1;
            }

            long long int temp = arr[j];
            for(int k = 0;k <= j;k++) {
                arr[k] -= temp;

                if(k == j) {
                    num_of_days += temp;
                    flag = 1;
                    j--;
                    
                }
            }
        }
        
    }

    cout << (num_of_days + 1) << endl;

    return 0;
}