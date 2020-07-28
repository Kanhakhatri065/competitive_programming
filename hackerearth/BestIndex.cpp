#include <bits/stdc++.h>

using namespace std;

int main(){
    int size;
    cin >> size;

    int arr[size];
    for(int i = 0;i < size;i++){
        cin >> arr[i];
    }
    
    int sum[size];
    for(int i = 0;i < size;i++){
        sum[i] = 0;
    }

    for(int i = 0;i < size;i++){
        int count = 1;
        int temp_sum = 0;
        for(int j = i;j < size;){
            int to_be_added = 0;
            int temp_count = count;

            while(temp_count != 0){
                to_be_added += arr[j];
                j++;
                if(j == size){
                    break;
                }
                temp_count--;
            } 
            
            if(j == size){
                break;
            }

            temp_sum += to_be_added;
            count++;
        }
        sum[i] = temp_sum;
    }

    sort(sum,sum + size);
    
    cout << sum[size - 1] << endl;

    return 0;
}