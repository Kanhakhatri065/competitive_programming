#include <iostream>
#include <limits.h>
using namespace std;

long long int max_subarray_sum(long long int arr[], long long int size){
    long long int max_so_far = LLONG_MIN;
    long long int max_ending_here = 0;

    for(long long int i = 0;i < size;i++){
        max_ending_here = max_ending_here + arr[i];
        if(max_so_far < max_ending_here){
            max_so_far = max_ending_here;
        }

        if(max_ending_here < 0){
            max_ending_here = 0;
        }
    } 

    return max_so_far;
}

int main(){
    int testcases;
    cin >> testcases;

    long long int size = 0;
    for(int i = 0;i < testcases;i++){
        cin >> size;

        long long int arr[size];
        for(long long int j = 0;j < size;j++){
            cin >> arr[j];
        }

        for(long long int j = 0;j < size;j++){
            cout << max_subarray_sum(arr,size) << " ";

            long long int temp = arr[0];
            for(long long int k = 1;k < size;k++){
                arr[k - 1] = arr[k];
            }
            arr[size - 1] = temp;
        }
        cout << endl;
    }
    return 0;
}