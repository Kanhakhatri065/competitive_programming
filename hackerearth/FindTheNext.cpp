#include <bits/stdc++.h>

using namespace std;

int main() {
    int size, queries;
    cin >> size >> queries;

    long long int arr[size];
    for(int i = 0;i < size;i++) {
        cin >> arr[i];
    }

    sort(arr, arr + size);

    long long int query;
    long long int output;
    for(int i = 0;i < queries;i++) {
        cin >> query;

        output = query + 1;
        
        int flag = 0;
        while(flag == 0) {
            for(int j = 0;j < size;j++) {
                if(output == arr[j]) {
                    output++;
                    break;
                }

                if(output != arr[j] && j == size - 1) {
                    flag = 1;
                    break;
                }
            }
        }

        cout << output << endl;
    }

    return 0;
}