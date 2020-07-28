#include <bits/stdc++.h>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    int size;
    for(int i = 0;i < testcases;i++){
        cin >> size;
        
        long long int arr[size];
        for(int j = 0;j < size;j++){
            cin >> arr[j];
        }

        long long int m=1000000007;

        long long int sum = 0;
        long long int check = pow(2, size - 1);
        for(int j = 0;j < size;j++){
            if(arr[j] >= check){
                sum += arr[j];
            }
        }

        cout << (sum%m) << endl;
    }
    return 0;
}